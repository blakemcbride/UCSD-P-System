# UCSD p-System: top-level build.
#
#   make            build native tools (xc, fs, vm) and the p-System volumes (os)
#   make test       run the native test suites
#   make run        boot the freshly built system volume in the VM
#   make install    install everything under PREFIX (default /usr/local)
#   make clean      remove all build output
#   make distclean  also remove run/ (the VM's working copies of the volumes)

PREFIX   ?= /usr/local
BUILD    := build
BUILD_OS := build-os
RUN_DIR  := run

# Directories holding the freshly built ucsdpsys_* tools, so the os build
# (and the tests) use them rather than anything installed on the system.
TOOL_PATH = $(shell find $(CURDIR)/$(BUILD)/subprojects -type f -executable \
	-name 'ucsdpsys*' ! -path '*.p/*' -printf '%h:' 2>/dev/null)
WITH_TOOLS = env PATH="$(TOOL_PATH)$$PATH"

.PHONY: all native os test run install clean distclean

all: os

$(BUILD)/build.ninja:
	meson setup --prefix=$(PREFIX) $(BUILD)

native: $(BUILD)/build.ninja
	meson compile -C $(BUILD)

$(BUILD_OS)/build.ninja: | native
	$(WITH_TOOLS) meson setup --prefix=$(PREFIX) \
		--cross-file os/cross/klebsch-stage1.ini $(BUILD_OS) os

os: native $(BUILD_OS)/build.ninja
	$(WITH_TOOLS) meson compile -C $(BUILD_OS)

test: native
	$(WITH_TOOLS) meson test -C $(BUILD) --print-errorlogs

# The VM writes to its volumes, so boot from copies.
run: os
	mkdir -p $(RUN_DIR)
	test -f $(RUN_DIR)/system.vol || cp $(BUILD_OS)/system.vol $(RUN_DIR)/
	test -f $(RUN_DIR)/utility.vol || cp $(BUILD_OS)/utility.vol $(RUN_DIR)/
	$(BUILD)/subprojects/ucsd-psystem-vm/ucsdpsys_vm/ucsdpsys_vm \
		-w $(RUN_DIR)/system.vol -w $(RUN_DIR)/utility.vol

install: all
	meson install -C $(BUILD)
	$(WITH_TOOLS) meson install -C $(BUILD_OS)

clean:
	rm -rf $(BUILD) $(BUILD_OS) subprojects/.wraplock

distclean: clean
	rm -rf $(RUN_DIR)
