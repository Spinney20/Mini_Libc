// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	// I have to use syscall with __NR_ftruncate which I found that
	// its defined in syscall_list.h as 77
	int ftruncate = syscall(77, fd, length);
	// checking for errors
	if (ftruncate < 0) {
		errno = -ftruncate;
		return -1;
	}
	return ftruncate;
}
