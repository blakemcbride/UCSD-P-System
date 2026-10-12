#!/bin/sh
#
# UCSD p-System cross compiler
# Copyright (C) 2012 Peter Miller
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at
# you option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>
#

TEST_SUBJECT="ucsdpsys_charset vs boot logo"
. test_prelude

# make a charset with an image in it
cat > example.text << 'fubar'
'P' = {
    "XXXXX ",
    " X   X",
    " X   X",
    " XXXX ",
    " X    ",
    " X    ",
    "XXX   ",
    "      ",
};
'M' = {
    "X    X ",
    "XX  XX  ",
    "X XX X ",
    "X XX X  ",
    "X    X ",
    "X    X",
    "X    X "
};
fubar
test $? -eq 0 || no_result

# example.png, as octal escapes (printf is portable, uudecode is not)
{
    printf '\211\120\116\107\015\012\032\012\000\000\000\015\111\110\104\122'
    printf '\000\000\000\100\000\000\000\100\001\003\000\000\000\220\247\343'
    printf '\235\000\000\000\001\163\122\107\102\000\256\316\034\351\000\000'
    printf '\000\006\120\114\124\105\377\377\377\000\000\000\125\302\323\176'
    printf '\000\000\000\103\111\104\101\124\050\317\143\370\017\005\014\015'
    printf '\014\140\300\070\312\300\301\340\077\170\340\001\204\361\360\041'
    printf '\204\301\123\010\143\030\156\114\200\062\066\103\031\205\223\022'
    printf '\240\212\347\101\031\007\241\014\036\306\036\014\106\003\056\306'
    printf '\140\015\015\130\262\001\000\212\302\103\020\131\324\102\030\000'
    printf '\000\000\000\111\105\116\104\256\102\140\202'
} > example.png
test $? -eq 0 || no_result

cat > ok << 'fubar'
#
# This file defines the shapes of the characters for drawing them on the
# screen.  This what is known as a bit-mapped font.
#
# Note that font outlines and bit-mapped fonts are not eligible for
# copyright protection.  Only fonts which contain computer code (e.g.
# some PostScript fonts) are eligible for copyright protection.
#

# LATIN CAPITAL LETTER M
'M' = {
    "X    X  ",
    "XX  XX  ",
    "X XX X  ",
    "X XX X  ",
    "X    X  ",
    "X    X  ",
    "X    X  ",
    "        ",
    "        ",
    "        ",
};

# LATIN CAPITAL LETTER P
'P' = {
    "XXXXX   ",
    " X   X  ",
    " X   X  ",
    " XXXX   ",
    " X      ",
    " X      ",
    "XXX     ",
    "        ",
    "        ",
    "        ",
};
fubar
test $? -eq 0 || no_result

# read example.text and example.png, write example.charset
ucsdpsys_charset -Aterak -e example.text example.charset example.png
test $? -eq 0 || fail

# verify file size
# it would be 2048 if it was just the font,
# but it will be 2560 if it is the font plus the boot logo.
sz=`ls -l example.charset | awk '{print $5}'`
if [ "$sz" -ne 2560 ]
then
    echo "size of the exmaple.charset -ne 2560" 1>&2
    fail
fi

ucsdpsys_charset -Aterak -d example.charset test.out.text test.out.png
test $? -eq 0 || fail

diff ok test.out.text
test $? -eq 0 || fail

if [ ! -s test.out.png ]
then
    echo "failed to create test.out.png" 1>&2
    fail
fi

#
# The functionality exercised by this test worked.
# No other assertions are made.
#
pass
# vim: set ts=8 sw=4 et :
