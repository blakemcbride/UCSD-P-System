# UCSD p-System: top-level build.  Requires GNU make 3.81 or later.
#
#   make            build the native tools and the p-System volumes
#   make test       run the native test suites
#   make run        boot the freshly built system volume in the VM
#   make install    install everything under PREFIX (default /usr/local)
#   make clean      remove all build output
#   make distclean  also remove run/ (the VM's working copies of the volumes)
#
# Optional parts are built when pkg-config finds their libraries.  Force
# them on or off with FUSE=yes|no, SDL=yes|no or PNG=yes|no.  CURSES=no
# drops the VM's terminal console (leaving the SDL3 window and batch mode).

PREFIX     ?= /usr/local
BINDIR     ?= $(PREFIX)/bin
DATADIR    ?= $(PREFIX)/share
MANDIR     ?= $(DATADIR)/man
DESTDIR    ?=

BISON      ?= bison
PKG_CONFIG ?= pkg-config
INSTALL    ?= install

CFLAGS     ?= -O2 -g
CXXFLAGS   ?= -O2 -g
LDFLAGS    ?=

# CC, CXX and AR come from make's defaults (cc, g++, ar) unless overridden.

have = $(shell $(PKG_CONFIG) --exists $(1) 2>/dev/null && echo yes || echo no)
FUSE ?= $(call have,fuse)
SDL  ?= $(call have,sdl3)
PNG  ?= $(call have,libpng)

CURSES ?= yes
ifeq ($(CURSES),yes)
CURSES_LIBS ?= $(shell $(PKG_CONFIG) --libs ncurses 2>/dev/null || echo -lcurses)
endif

# The VM's console backends: an SDL3 window and/or the terminal.
VM_CONSOLE_CFLAGS :=
VM_CONSOLE_LIBS   := $(CURSES_LIBS)
ifeq ($(CURSES),yes)
VM_CONSOLE_CFLAGS += -DHAVE_CURSES
endif
ifeq ($(SDL),yes)
VM_CONSOLE_CFLAGS += -DHAVE_SDL $(shell $(PKG_CONFIG) --cflags sdl3)
VM_CONSOLE_LIBS   += $(shell $(PKG_CONFIG) --libs sdl3)
endif

B     := build
BIN   := $(B)/bin
OBJ   := $(B)/obj
OSB   := $(B)/os
RUN   := run

EXPLAIN := subprojects/libexplain
XC      := subprojects/ucsd-psystem-xc
FS      := subprojects/ucsd-psystem-fs
VM      := subprojects/ucsd-psystem-vm
OS      := os

WARN     := -Wall
CPPFLAGS_ALL := -D_FILE_OFFSET_BITS=64 -I$(EXPLAIN)
DEPFLAGS := -MMD -MP

ifeq ($(PNG),yes)
PNG_CFLAGS := $(shell $(PKG_CONFIG) --cflags libpng)
PNG_LIBS   := $(shell $(PKG_CONFIG) --libs libpng)
else
PNG_CFLAGS := -DNO_PNG
PNG_LIBS   :=
endif

.PHONY: all native os test run install clean distclean
.SUFFIXES:
.DELETE_ON_ERROR:
.SECONDARY:

all: native os

# Every compiler output gets its own directory.
mkdir_p = @mkdir -p $(@D)

# ----------------------------------------------------------------------
# Compiling

# $(call objs,<dir>,<ext>): object files for every source under <dir>
objs = $(patsubst %,$(OBJ)/%.o,$(shell find $(1) -name '*.$(2)' | sort))

$(OBJ)/$(EXPLAIN)/%.c.o: $(EXPLAIN)/%.c
	$(mkdir_p)
	$(CC) $(CPPFLAGS_ALL) $(CPPFLAGS) $(WARN) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ)/$(VM)/%.c.o: $(VM)/%.c
	$(mkdir_p)
	$(CC) $(CPPFLAGS_ALL) -I$(VM) -DTURTLEGRAPHICS $(VM_EXTRA) $(CPPFLAGS) $(WARN) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ)/$(FS)/%.cc.o: $(FS)/%.cc
	$(mkdir_p)
	$(CXX) $(CPPFLAGS_ALL) -I$(FS) $(FS_EXTRA) $(CPPFLAGS) $(WARN) -std=c++17 $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ)/$(XC)/%.cc.o: $(XC)/%.cc
	$(mkdir_p)
	$(CXX) $(CPPFLAGS_ALL) -I$(XC) $(PNG_CFLAGS) $(XC_EXTRA) $(CPPFLAGS) $(WARN) -std=c++17 $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# The bison-generated parsers (grammar.yacc.cc and .h) are checked in.
# They are regenerated from grammar.y only when bison 3 or later is
# available; older versions (such as macOS's 2.3) are ignored.
BISON_MAJOR := $(shell $(BISON) --version 2>/dev/null | sed -n '1s/.* \([0-9][0-9]*\)\.[0-9].*/\1/p')
ifneq ($(filter-out 0 1 2,$(BISON_MAJOR)),)
$(XC)/%.yacc.cc $(XC)/%.yacc.h: $(XC)/%.y
	$(BISON) -Wno-yacc -Wno-conflicts-sr -Wno-conflicts-rr \
		--defines=$(XC)/$*.yacc.h --output=$(XC)/$*.yacc.cc $<
endif

# The install directories are compiled into the cross compiler.
$(OBJ)/$(XC)/lib/libdir.cc.o: XC_EXTRA = -DBINDIR='"$(BINDIR)"' \
	-DDATADIR='"$(DATADIR)"' -DDATAROOTDIR='"$(DATADIR)"' \
	-DMANDIR='"$(MANDIR)"' -DPREFIX='"$(PREFIX)"'

# ----------------------------------------------------------------------
# Libraries

EXPLAIN_LIB := $(B)/libexplain.a
VM_LIB      := $(B)/libvm.a
FS_LIB      := $(B)/libfs.a
XC_LIB      := $(B)/libxc.a

$(EXPLAIN_LIB): $(call objs,$(EXPLAIN),c)
$(VM_LIB): $(call objs,$(VM)/lib,c)
$(FS_LIB): $(call objs,$(FS)/lib,cc)
$(XC_LIB): $(call objs,$(XC)/lib,cc)

$(B)/lib%.a:
	@rm -f $@
	$(AR) rcs $@ $^


# ----------------------------------------------------------------------
# Programs.  Each one is built from every source in its directory.

XC_PROGS := ucsdpsys ucsdpsys_assemble ucsdpsys_charset ucsdpsys_compile \
	ucsdpsys_depends ucsdpsys_disassemble ucsdpsys_downcase ucsdpsys_errors \
	ucsdpsys_foto ucsdpsys_libmap ucsdpsys_librarian ucsdpsys_link \
	ucsdpsys_littoral ucsdpsys_opcodes ucsdpsys_osmakgen ucsdpsys_pretty \
	ucsdpsys_setup
XC_TESTS := test_cardinal test_long_integer

FS_PROGS := ucsdpsys_disk ucsdpsys_fsck ucsdpsys_interleave ucsdpsys_logo \
	ucsdpsys_mkfs ucsdpsys_rt11 ucsdpsys_text
ifeq ($(FUSE),yes)
FS_PROGS += ucsdpsys_mount ucsdpsys_umount
endif
FS_TESTS := test_rdwr test_statfs

VM_PROGS := ucsdpsys_vm
ifeq ($(SDL),yes)
VM_PROGS += ucsdpsys_turtleserver
endif

PROGS     := $(XC_PROGS) $(FS_PROGS) $(VM_PROGS)
TEST_BINS := $(XC_TESTS) $(FS_TESTS)

XC_LDLIBS := $(XC_LIB) $(EXPLAIN_LIB)
FS_LDLIBS := $(FS_LIB) $(EXPLAIN_LIB)
VM_LDLIBS := $(VM_LIB) $(EXPLAIN_LIB)

define xc_prog
$(BIN)/$(1): $(call objs,$(XC)/$(1),cc) $(XC_LDLIBS)
	$$(mkdir_p)
	$$(CXX) $$(LDFLAGS) -o $$@ $$^ $$(PNG_LIBS)
endef
$(foreach p,$(XC_PROGS) $(XC_TESTS),$(eval $(call xc_prog,$(p))))

define fs_prog
$(BIN)/$(1): $(call objs,$(FS)/$(1),cc) $(FS_LDLIBS)
	$$(mkdir_p)
	$$(CXX) $$(LDFLAGS) -o $$@ $$^ $$(FS_LIBS_$(1))
endef
$(foreach p,$(FS_PROGS) $(FS_TESTS),$(eval $(call fs_prog,$(p))))

ifeq ($(FUSE),yes)
$(call objs,$(FS)/ucsdpsys_mount,cc): FS_EXTRA = $(shell $(PKG_CONFIG) --cflags fuse)
FS_LIBS_ucsdpsys_mount := $(shell $(PKG_CONFIG) --libs fuse)
endif

$(call objs,$(VM)/ucsdpsys_vm,c): VM_EXTRA = $(VM_CONSOLE_CFLAGS)

$(BIN)/ucsdpsys_vm: $(call objs,$(VM)/ucsdpsys_vm,c) $(VM_LDLIBS)
	$(mkdir_p)
	$(CC) $(LDFLAGS) -o $@ $^ $(VM_CONSOLE_LIBS) -lm

# Turtle graphics window, started by the VM on demand.
ifeq ($(SDL),yes)
$(call objs,$(VM)/ucsdpsys_turtleserver,c): VM_EXTRA = $(shell $(PKG_CONFIG) --cflags sdl3)
endif

$(BIN)/ucsdpsys_turtleserver: $(call objs,$(VM)/ucsdpsys_turtleserver,c) $(VM_LDLIBS)
	$(mkdir_p)
	$(CC) $(LDFLAGS) -o $@ $^ $(shell $(PKG_CONFIG) --libs sdl3) -lm

native: $(addprefix $(BIN)/,$(PROGS) $(TEST_BINS))

-include $(shell [ -d $(OBJ) ] && find $(OBJ) -name '*.d')

# ----------------------------------------------------------------------
# The p-System itself, cross compiled from os/ with the tools above.

ARCH     := p-code-le
DISK_KB  := 256

PC       := $(BIN)/ucsdpsys_compile --arch=$(ARCH) -Wno-shadow
AS       := $(BIN)/ucsdpsys_assemble --arch=6502
LIBR     := $(BIN)/ucsdpsys_librarian
LINK     := $(BIN)/ucsdpsys_link
SETUP    := $(BIN)/ucsdpsys_setup
MKFS     := $(BIN)/ucsdpsys_mkfs
DISK     := $(BIN)/ucsdpsys_disk

# $(call pascal,<dir>,<output>,<extra flags>): compile <dir>/main.text.
# Any .text file in the directory may be an include file.
define pascal
$(OSB)/$(1)/$(2): $(OS)/$(1)/main.text $(wildcard $(OS)/$(1)/*.text) $(BIN)/ucsdpsys_compile
	$$(mkdir_p)
	$$(PC) $(3) -I$$(@D) -I$(OS)/$(1) -o $$@ $$<
endef

# $(call syslib,<dir>,<input>,<output>): strip the system segments.
define syslib
$(OSB)/$(1)/$(3): $(OSB)/$(1)/$(2) $(BIN)/ucsdpsys_librarian
	$$(LIBR) -o $$@ --file=$$< --remove-system-segments
endef

# Programs that need the shared include files copied beside them.
$(OSB)/%/globals.text: $(OS)/system/globals.text
	$(mkdir_p)
	cp $< $@
$(OSB)/%/vstamp.inc.text: $(OS)/etc/vstamp.inc.text
	$(mkdir_p)
	cp $< $@

SYS := -fignore-undefined-segment-zero

# Plain programs: <dir>:<output>
PLAIN := binder:binder.code bios.diag:bios.diag.code calc:calc.code \
	copydupdir:copydupdir.code diagnostic:system.pascal \
	disassembler:disassembl.code edittort11:edittort11.code \
	execerr:execerr.code libmap:libmap.code markdupdir:markdupdir.code \
	radix:radix.code rt11toedit:rt11toedit.code xref:xref.code
$(foreach p,$(PLAIN),$(eval $(call pascal,$(word 1,$(subst :, ,$(p))),$(word 2,$(subst :, ,$(p))),)))

# System programs, linked through the librarian: <dir>:<output>
SYSPROGS := basic:basic.code compiler:system.compiler editor:system.editor \
	filer:system.filer librarian:librarian.code linker:system.linker \
	pascalio:system.pascalio setup:setup.code yaloe:yaloe.code
$(foreach p,$(SYSPROGS),$(eval $(call pascal,$(word 1,$(subst :, ,$(p))),main.code,$(SYS))))
$(foreach p,$(SYSPROGS),$(eval $(call syslib,$(word 1,$(subst :, ,$(p))),main.code,$(word 2,$(subst :, ,$(p))))))

$(OSB)/system/system.pascal: $(OS)/system/main.text $(wildcard $(OS)/system/*.text) \
		$(OSB)/system/globals.text $(OSB)/system/vstamp.inc.text $(BIN)/ucsdpsys_compile
	$(mkdir_p)
	$(PC) -I$(@D) -I$(OS)/system -o $@ $<

GLOBALS := compiler editor filer linker long_integer pascalio \
	transcendental turtle_graphics yaloe
VSTAMP  := compiler editor filer linker long_integer transcendental turtle_graphics
$(foreach d,$(GLOBALS),$(eval $(OSB)/$(d)/main.code $(OSB)/$(d)/main.pas.code: $(OSB)/$(d)/globals.text))
$(foreach d,$(VSTAMP),$(eval $(OSB)/$(d)/main.code $(OSB)/$(d)/main.pas.code: $(OSB)/$(d)/vstamp.inc.text))

$(OSB)/compiler/system.syntax: $(OS)/compiler/error-messages.text
	$(mkdir_p)
	cp $< $@

$(OSB)/host/klebsch/system.miscinfo: $(OS)/host/klebsch/miscinfo.text $(BIN)/ucsdpsys_setup
	$(mkdir_p)
	$(SETUP) --arch=$(ARCH) --encode $< $@

# Library units: Pascal half plus a 6502 assembler half, linked together.
UNITS := long_integer transcendental turtle_graphics
$(foreach u,$(UNITS),$(eval $(call pascal,$(u),main.pas.code,$(SYS))))
$(foreach u,$(UNITS),$(eval $(OSB)/$(u)/main.code: $(OSB)/$(u)/main.pas.code $(OSB)/host/klebsch/$(u)/main.asm.code))

$(OSB)/host/klebsch/%/main.asm.code: $(OS)/host/klebsch/%/main.asm.text $(BIN)/ucsdpsys_assemble
	$(mkdir_p)
	$(AS) -I$(OSB) -I$(<D) -o $@ $<

$(addprefix $(OSB)/,$(addsuffix /main.code,$(UNITS))): $(BIN)/ucsdpsys_link
	$(LINK) -o $@ $(filter %.code,$^)

$(OSB)/system/system.library: $(addprefix $(OSB)/,$(addsuffix /main.code,long_integer transcendental turtle_graphics)) \
		$(OSB)/pascalio/system.pascalio $(BIN)/ucsdpsys_librarian
	$(LIBR) --create $@ \
		--copy $(OSB)/long_integer/main.code --segment longinte=30 \
		--copy $(OSB)/pascalio/system.pascalio --segment pascalio=31 \
		--copy $(OSB)/transcendental/main.code --segment transcen=29 \
		--copy $(OSB)/turtle_graphics/main.code --segment turtlegr=15

# Disk volumes.  The volume label is the file name without '.vol'.
VOLUMES := $(B)/system.vol $(B)/utility.vol $(B)/diagnostic.vol

$(B)/system.vol: $(addprefix $(OSB)/,system/system.pascal host/klebsch/system.miscinfo \
	compiler/system.compiler editor/system.editor filer/system.filer \
	system/system.library linker/system.linker compiler/system.syntax)
$(B)/utility.vol: $(addprefix $(OSB)/,basic/basic.code binder/binder.code \
	bios.diag/bios.diag.code calc/calc.code copydupdir/copydupdir.code \
	disassembler/disassembl.code edittort11/edittort11.code execerr/execerr.code \
	libmap/libmap.code librarian/librarian.code markdupdir/markdupdir.code \
	radix/radix.code rt11toedit/rt11toedit.code setup/setup.code \
	xref/xref.code yaloe/yaloe.code)
$(B)/diagnostic.vol: $(OSB)/diagnostic/system.pascal

$(VOLUMES): $(BIN)/ucsdpsys_mkfs $(BIN)/ucsdpsys_disk
	@rm -f $@
	$(MKFS) --label=$(basename $(@F)) --arch=$(ARCH) -B$(DISK_KB) $@
	$(DISK) -f $@ --put $(filter $(OSB)/%,$^)
	$(DISK) -f $@ --crunch --list --sort=name

os: $(VOLUMES)

# ----------------------------------------------------------------------
# Tests.  A test passes when its script exits 0.

FS_NEEDS_FUSE := t0002a t0003a t0005a t0007a t0008a t0009a t0010a
XC_NEEDS_PNG  := t0736a

TEST_SKIP :=
ifneq ($(FUSE),yes)
TEST_SKIP += $(addprefix $(FS)/test/00/,$(addsuffix .sh,$(FS_NEEDS_FUSE)))
endif
ifneq ($(PNG),yes)
TEST_SKIP += $(addprefix $(XC)/test/07/,$(addsuffix .sh,$(XC_NEEDS_PNG)))
endif

TESTS := $(filter-out $(TEST_SKIP),$(sort $(wildcard $(XC)/test/*/t*.sh $(FS)/test/*/t*.sh $(VM)/test/*/t*.sh)))

test: native
	@pass=0; fail=0; failed=; bin=$(abspath $(BIN)); \
	for t in $(TESTS); do \
		proj=`echo $$t | cut -d/ -f1-2`; \
		if PATH="$$bin:`pwd`/$$proj/script:$$PATH" sh $$t > $(B)/test.log 2>&1; then \
			pass=`expr $$pass + 1`; \
		else \
			fail=`expr $$fail + 1`; failed="$$failed $$t"; \
			echo "FAIL: $$t"; cat $(B)/test.log; \
		fi; \
	done; \
	rm -f $(B)/test.log; \
	echo "Passed: $$pass  Failed: $$fail  Skipped: $(words $(TEST_SKIP))"; \
	test $$fail -eq 0

# ----------------------------------------------------------------------
# Running and installing

# The VM writes to its volumes, so boot from copies.
run: $(BIN)/ucsdpsys_vm os
	mkdir -p $(RUN)
	test -f $(RUN)/system.vol || cp $(B)/system.vol $(RUN)/
	test -f $(RUN)/utility.vol || cp $(B)/utility.vol $(RUN)/
	$(BIN)/ucsdpsys_vm -w $(RUN)/system.vol -w $(RUN)/utility.vol

MAN1 := $(wildcard $(XC)/man/man1/*.1 $(FS)/man/man1/*.1 $(VM)/man/man1/*.1 $(OS)/man/man1/*.1)
MAN5 := $(wildcard $(XC)/man/man5/*.5 $(FS)/man/man5/*.5)
ifneq ($(FUSE),yes)
MAN1 := $(filter-out %/ucsdpsys_mount.1 %/ucsdpsys_umount.1,$(MAN1))
endif
ifneq ($(SDL),yes)
MAN1 := $(filter-out %/ucsdpsys_turtleserver.1,$(MAN1))
endif

install: all
	$(INSTALL) -d $(DESTDIR)$(BINDIR) $(DESTDIR)$(MANDIR)/man1 \
		$(DESTDIR)$(MANDIR)/man5 $(DESTDIR)$(DATADIR)/ucsd-psystem-os
	$(INSTALL) -m 755 $(addprefix $(BIN)/,$(PROGS)) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 644 $(MAN1) $(DESTDIR)$(MANDIR)/man1
	$(INSTALL) -m 644 $(MAN5) $(DESTDIR)$(MANDIR)/man5
	$(INSTALL) -m 644 $(VOLUMES) $(DESTDIR)$(DATADIR)/ucsd-psystem-os

clean:
	rm -rf $(B)

distclean: clean
	rm -rf $(RUN)
