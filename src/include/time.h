#ifndef	__TIME_H__
#define	__TIME_H__ 1

//I guess the orignal time.h has more stuff
// like years or smth but I only need
// seconds and nanoseconds for nanosleep to work and
// my tests to pass

struct timespec {
    long tv_sec;
    long tv_nsec;
};

unsigned int nanosleep(const struct timespec *request, struct timespec *remaining);

#endif
