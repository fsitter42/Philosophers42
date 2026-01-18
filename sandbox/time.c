#include <stdio.h> // printf
#include <sys/time.h> // time
#include <stdint.h> // uint64_t
#include <unistd.h> // usleep


uint64_t gettime(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void ex1()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	//usleep(500000);
	printf("%ld seconds\n", time.tv_sec);
	printf("%ld microseconds\n", time.tv_usec);

	printf("\n%ld years passed since 1970\n", time.tv_sec / 60 / 60 / 24 / 365);
}


void ex2()
{
	uint64_t start;
	uint64_t now_time;

	start = gettime();
	//usleep(530000);
	now_time = gettime();

	printf("\n%ld milliseconds since start\n", now_time - start);

}

int main(void)
{
	ex1();
	ex2();
}