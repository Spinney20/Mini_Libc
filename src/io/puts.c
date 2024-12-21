#include <stdio.h>
#include <string.h>
#include <internal/syscall.h>

int puts(const char *s)
{
    // i have to write the message and then a newline
    // so two syscalls
    // the syscall for the message, write is number 1
    int message = syscall(1, 1, s, strlen(s));
    if (message < 0)
    {
        return -1;
    }
    // the syscall for writing the newline
    int newline = syscall(1, 1, "\n", 1);
    if (newline < 0)
    {
        return -1;
    }

    // if everything is ok I return 1
    return 1;
}
