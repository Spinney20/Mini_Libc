#include <stdio.h>
#include <time.h>
#include <unistd.h>

//For this one I had to make time.h as well
//I had to make the struct timespec because
// nanosleep was using it by default
// I only needed seconds and nanoseconds so
// I only added those, for more check sys/time.h
unsigned int sleep(unsigned int seconds) {
    //now to the sleep
    // Sleep is not a syscall so I will call nanosleep, thats the whole point
    // i guess

    // I have to make a struct timespec
    // rquest is the time I want to sleep
    // remaining is the time left to sleep
    // both will be needed for calling nanosleep
    struct timespec request, remaining;
    // setting the requested seconds and 0 nanoseconds
    request.tv_sec = seconds;
    request.tv_nsec = 0;

    // returning the result of nanosleep
    return nanosleep(&request, &remaining);
}
