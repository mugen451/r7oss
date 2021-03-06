/*
 *   Copyright (c) International Business Machines Corp., 2000-2002
 *
 *   This program is free software;  you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;  without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 *   the GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program;  if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef H_INITMAP
#define H_INITMAP

#define ALLOC		0x1
#define FREE		0x2
#define BADBLOCK	0x4

int calc_map_size(int64_t, struct dinode *, int, int *, unsigned);
int markit(int64_t, unsigned);
int record_LVM_BadBlks( int, int, int, struct dinode *, int64_t );
int verify_last_blocks( FILE *, int, struct dinode * );
int write_block_map(FILE *, int64_t, int);

#endif	/* H_INITMAP */
