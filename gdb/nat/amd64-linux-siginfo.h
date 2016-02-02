/* Low-level siginfo manipulation for amd64.

   Copyright (C) 2016 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef AMD64_LINUX_SIGINFO_H
#define AMD64_LINUX_SIGINFO_H 1


/* When GDB is built as a 64-bit application on Linux, the
   PTRACE_GETSIGINFO data is always presented in 64-bit layout.  Since
   debugging a 32-bit inferior with a 64-bit GDB should look the same
   as debugging it with a 32-bit GDB, we do the 32-bit <-> 64-bit
   conversion in-place ourselves.  */

/* Kind of siginfo fixup to be performed.  */

enum amd64_siginfo_fixup_mode
{
  FIXUP_32 = 1,   /* Fixup for 32bit.  */
  FIXUP_X32 = 2   /* Fixup for x32.  */
};

/* Common code for performing the fixup of the siginfo.  */

int amd64_linux_siginfo_fixup_common (siginfo_t *native, gdb_byte *inf,
				      int direction,
				      enum amd64_siginfo_fixup_mode mode);

#endif