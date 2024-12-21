#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>

// I added timespec struct in time.h
// It was needed for the arguments of nanosleep
unsigned int nanosleep(const struct timespec *request, struct timespec *remaining) {
    // the nanosleep is just a syscall
    // with __NR_nanosleep which is 35
    int ret = syscall(__NR_nanosleep, request, remaining);
    return ret;
}
