//
// UCSD p-System cross compiler
// Copyright (C) 2010, 2012 Peter Miller
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or (at
// you option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program. If not, see <http://www.gnu.org/licenses/>
//

#include <lib/libdir.h>

// The install directories are passed in by the Makefile.
#ifndef PREFIX
#define PREFIX "/usr/local"
#endif
#ifndef BINDIR
#define BINDIR PREFIX "/bin"
#endif
#ifndef LIBDIR
#define LIBDIR PREFIX "/lib"
#endif
#ifndef DATAROOTDIR
#define DATAROOTDIR PREFIX "/share"
#endif
#ifndef DATADIR
#define DATADIR DATAROOTDIR
#endif
#ifndef MANDIR
#define MANDIR DATAROOTDIR "/man"
#endif
#ifndef SYSCONFDIR
#define SYSCONFDIR PREFIX "/etc"
#endif


const char *
configured_bindir(void)
{
    return BINDIR;
}


const char *
configured_libdir(void)
{
    return LIBDIR;
}


const char *
configured_datarootdir(void)
{
    return DATAROOTDIR;
}


const char *
configured_datadir(void)
{
    return DATADIR;
}


const char *
configured_mandir(void)
{
    return MANDIR;
}


const char *
configured_sysconfdir(void)
{
    return SYSCONFDIR;
}


// vim: set ts=8 sw=4 et :
