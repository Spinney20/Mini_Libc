// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	// I have to use syscall with __NR_close which I found that
	// its defined in syscall_list.h as 3
	return syscall(3, fd);
}
