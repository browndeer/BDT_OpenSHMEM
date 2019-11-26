/* atomic_inc.c
 *
 * Copyright (c) 2016 U.S. Army Research Laboratory.  All rights reserved.
 * Copyright (c) 2019 Brown Deer Technology, LLC. All rights reserved.
 *
 * This file is part of the BDT OpenSHMEM Reference Implementation software
 * package. For license information, see the LICENSE file in the top level
 * directory of the distribution.
 *
 */

/*
 * Performance test for shmem_int_atomic_inc
 */

#include <stdio.h>
#include <shmem.h>
#include "ctimer.h"

#define NLOOP 10000

int main (void)
{
	int i, npe;
	static int dest;
	static unsigned int t, tsum;
	static int pWrk[SHMEM_REDUCE_MIN_WRKDATA_SIZE];
	static long pSync[SHMEM_REDUCE_SYNC_SIZE];
	for (i = 0; i < SHMEM_REDUCE_SYNC_SIZE; i++) {
		pSync[i] = SHMEM_SYNC_VALUE;
	}

	shmem_init();
	int me = shmem_my_pe();
	int npes = shmem_n_pes();

	if (me == 0) {
		printf("# SHMEM Atomic Increment Performance for variable NPES\n"
			"# NPES\tLatency (nanoseconds)\n");
	}

	for (npe = 2; npe <= npes; npe++)
	{
		int nxtpe = me + 1;
		if (nxtpe >= npe) nxtpe -= npe;

		dest = 0;
		shmem_barrier_all();
		ctimer_start();

		if (me < npe) {
			t = ctimer();
			for (i = 0; i < NLOOP; i++) {
				shmem_int_atomic_inc(&dest, nxtpe);
			}
			t -= ctimer();
			shmem_int_sum_to_all(&tsum, &t, 1, 0, 0, npe, pWrk, pSync);
		}


		if (me == 0) {
			unsigned int nsec = ctimer_nsec(tsum / (npe * NLOOP));
			printf("%5d %7u\n", npe, nsec);
		}

		if (me < npe) {
			if (dest != NLOOP) printf("# %d: ERROR %d\n", me, dest);
		} else {
			if (dest != 0) printf("# %d: ERROR %d\n", me, dest);
		}
	}
	shmem_finalize();

	return 0;
}
