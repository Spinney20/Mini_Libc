// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	// Same as fstat but with __NR_stat which I found that
	// its defined in syscall_list.h as 4
	// I have to check if the syscall is negative
	// Because i fail a test if i dont do it
	int stat = syscall(__NR_stat, path, buf);
	if (stat < 0) {
		errno = -stat;
		return -1;
	}
	return stat;
}
