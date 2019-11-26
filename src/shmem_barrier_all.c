/* shmem_barrier_all.c
 *
 * Copyright (c) 2016 U.S. Army Research Laboratory.  All rights reserved.
 * Copyright (c) 2019 Brown Deer Technology, LLC. All rights reserved.
 *
 * This file is part of the BDT OpenSHMEM Reference Implementation software
 * package. For license information, see the LICENSE file in the top level
 * directory of the distribution. 
 *
 */

#include "internals.h"
#include "shmem.h"

SHMEM_SCOPE
void shmem_barrier_all(void)
{
	shmem_quiet();
	shmem_sync_all();
}

