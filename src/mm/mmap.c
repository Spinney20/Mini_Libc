// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

//All of these are just syscall fortunatelly for me
// I found the syscall arguments in the syscall_list.h file
// A also treated the error cases for each syscall
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long ret = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (ret < 0) {
		errno = -ret;
		return MAP_FAILED;
	}
	return (void *)ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long ret = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (ret < 0) {
		errno = -ret;
		return MAP_FAILED;
	}
	return (void *)ret;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long ret = syscall(__NR_munmap, addr, length);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
