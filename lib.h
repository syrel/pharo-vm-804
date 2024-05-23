typedef long sqInt ;
typedef sqInt signalSemaphoreWithIndex(sqInt);

extern void signal_semaphore(signalSemaphoreWithIndex* signaller, sqInt index, int times, int delay);
extern void raise_signal(int signal, int times, int delay);
int msleep(long msec);