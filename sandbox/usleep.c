#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void ex()
{
	struct timeval starttime;
	struct timeval endtime;

	long sleep_soll = 200 * 1000;
	long sleep_ist;

	gettimeofday(&starttime, NULL);
	usleep(sleep_soll);
	gettimeofday(&endtime, NULL);

	sleep_ist = (endtime.tv_sec - starttime.tv_sec) * 1000000 + (endtime.tv_usec - starttime.tv_usec);

	printf("Requested Sleep Time: %ld microseconds\n", sleep_soll);
    printf("Actual Sleep Time: %ld microseconds\n", sleep_ist);
}

int main()
{
	ex();
}