// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	//Its just a syscall with __NR_fstat which I found that
	// its defined in syscall_list.h as 5

	int fstat = syscall(__NR_fstat, fd, st);

	// But apparently if the fd is bad, I fail a test
	// so I have to check with that the syscall
	// is not negative
	// and if it is I have to set errno to the negative value
	// of the syscall and return -1
	if (fstat < 0) {
		errno = -fstat;
		return -1;
	}
	return fstat;
}
