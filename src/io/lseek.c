// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	// same syscall, now with __NR_lseek which I found that
	// its defined in syscall_list.h as 8
	int seek = syscall(8, fd, offset, whence);
	// ofc errors
	if (seek < 0) {
		errno = -seek;
		return -1;
	}
	return seek;
}
