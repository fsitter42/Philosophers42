#include <stdio.h> // printf
#include <stdlib.h> //malloc
#include <pthread.h>
#include <unistd.h>

void *p_hello(void *p)
{
	int i = 0;
	while (i < 6)
	{
		printf("Hello\n");
		i++;
		usleep(600);
	}
	return (NULL);
}

void *p_bye(void *p)
{
	int i = 0;
	while (i < 6)
	{
		printf("\t\tWorld\n");
		i++;
		usleep(600);
	}
	return (NULL);
}

void ex1()
{
	p_hello(NULL);
	p_bye(NULL);
}

void ex2()
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, p_hello, NULL))
		exit(1);
	if (pthread_create(&t2, NULL, p_bye, NULL))
		exit(1);
	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
	printf("hi\n");
}


int main()
{
	ex2();
}

