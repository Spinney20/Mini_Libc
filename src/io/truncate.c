// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	// I have to use syscall with __NR_truncate which I found that
	// its defined in syscall_list.h as 76
	int truncate = syscall(76, path, length);
	if (truncate < 0) {
		errno = -truncate;
		return -1;
	}
	return truncate;
}
