dnl* shmem_iget_x.m4
dnl*
dnl* Copyright (c) 2016 U.S. Army Research Laboratory.  All rights reserved.
dnl* Copyright (c) 2019 Brown Deer Technology, LLC. All rights reserved.
dnl*
dnl* This file is part of the BDT OpenSHMEM Reference Implementation software
dnl* package. For license information, see the LICENSE file in the top level
dnl* directory of the distribution.
dnl*

define(decl_shmem_iget_x,
`void shmem_iget$1( void *dest, const void *source, ptrdiff_t dst,
	ptrdiff_t sst, size_t nelems, int pe);'
)

define(func_shmem_iget_x,
`void shmem_iget$1( void *dest, const void *source, ptrdiff_t dst,
	ptrdiff_t sst, size_t nelems, int pe)
{
	int it, is, n = dst*nelems;

	$2* pdst = ($2*)dest;

	$2* psrc = ($2*)shmem_ptr(source,pe);

	for (it = 0, is = 0; it < n; it += dst, is += sst) {
		pdst[it] = psrc[is];
	} 
}'
)
