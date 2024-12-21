// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	//getting the next argument/s
	va_list args;
	va_start(args, flags);
	int next_arg = va_arg(args, int);
	va_end(args);

	// I have to use syscall with __NR_open which I found that
	// its defined in syscall_list.h as 2
	int ret = syscall(2, filename, flags, next_arg);
	// checking for errors
	if( ret < 0 ) {
		errno = -ret;
		return -1;
	}
	return ret;
}
