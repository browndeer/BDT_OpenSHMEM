/* shmem_info_get_version.c
 *
 * Copyright (c) 2016 U.S. Army Research Laboratory.  All rights reserved.
 * Copyright (c) 2019 Brown Deer Technology, LLC. All rights reserved.
 *
 * This file is part of the BDT OpenSHMEM Reference Implementation software
 * package. For license information, see the LICENSE file in the top level
 * directory of the distribution. 
 *
 */

#include "shmem.h"
#include "internals.h"

SHMEM_SCOPE
void shmem_info_get_version(int *major, int *minor)
{
	*major = SHMEM_MAJOR_VERSION;
	*minor = SHMEM_MINOR_VERSION;
}
