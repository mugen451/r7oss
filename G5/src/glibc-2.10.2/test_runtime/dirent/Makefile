# Copyright (C) 1991-2000,2002,2003,2005,2006 Free Software Foundation, Inc.
# This file is part of the GNU C Library.

# The GNU C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.

# The GNU C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with the GNU C Library; if not, write to the Free
# Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
# 02111-1307 USA.

#
#	Sub-makefile for dirent portion of the library.
#

include ../config.make

TESTS	   := list tst-seekdir opendir-tst1 bug-readdir1 tst-fdopendir \
	      tst-fdopendir2


OPTS_opendir-tst1 = --test-dir=../dirent

include ../Test.mak

TOBEINSTALLED=$(TOBEINSTALLED_BIN) $(TOBEINSTALLED_SH)

.PHONY: $(TOBEINSTALLED)

install: $(TOBEINSTALLED)
ifneq ("n$(TOBEINSTALLED)n","n n")
	@echo "Installing dirent...."
	@cp -fr $(foreach f,$^, $(OBJPFX)/$f) .
else
	@echo "Nothing to install for dirent."
endif
