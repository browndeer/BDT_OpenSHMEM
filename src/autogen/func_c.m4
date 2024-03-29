dnl* func_c.m4
dnl*
dnl* Copyright (c) 2016 U.S. Army Research Laboratory.  All rights reserved.
dnl* Copyright (c) 2019 Brown Deer Technology, LLC. All rights reserved.
dnl*
dnl* This file is part of the BDT OpenSHMEM Reference Implementation software
dnl* package. For license information, see the LICENSE file in the top level
dnl* directory of the distribution.
dnl*

define(func_c,
/* $1
 *
 * This source file is autogenerated Do not edit.
 */

#include "shmem.h"
#include "internals.h"

`include($2.m4)'

func_$2($3)
)
