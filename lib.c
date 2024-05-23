#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#include "lib.h"

void signal_semaphore(signalSemaphoreWithIndex* signaller, sqInt index, int times, int delay) {
    for (int i = 0; i < times; i++) {
        if (delay > 0) {
            msleep(delay);
        }
        if (i % 1000 == 0) {
            printf("signalSemaphoreWithIndex(%ld) #%i \n", index, i);
        }
        signaller(index);
    }
}

void raise_signal(int signal, int times, int delay) {
    for (int i = 0; i < times; i++) {
        if (delay > 0) {
            msleep(delay);
        }

        if (i % 1000 == 0) {
            printf("raise(SIGUSR1) #%i \n", i);
        }
        raise(signal);
    }
}

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}
