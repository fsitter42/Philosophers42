#include <stdio.h> // printf
#include <stdlib.h> //malloc
#include <pthread.h>
#include <unistd.h>

typedef struct s
{
    int num;
    pthread_mutex_t mutex;
} t;

t *init(void)
{
    t   *data;

    data = malloc(sizeof(t));
    if (!data)
        exit (1);

    data->num = 0;
    pthread_mutex_init(&data->mutex, NULL);
    return (data);
}

void free_t(t *data)
{
    pthread_mutex_destroy(&data->mutex);
    free(data);
}

void free_on_error(t *data, int exitcode)
{
    free_t(data);
    //free(data);
    exit(exitcode);
}

void *r1(void *arg)
{
    t *data = (t *)arg;
    int i = 0;

    while (i < 600)
    {
        pthread_mutex_lock(&data->mutex);
        (data->num)++;
        pthread_mutex_unlock(&data->mutex);
        i++;
    }
    return (NULL);
}

void ex(void)
{
    t *data = init();
    pthread_t t1;
    pthread_t t2;

    printf("%i\n", data->num);

    if (pthread_create(&t1, NULL, r1, data))
        free_on_error(data, 2);
    if (pthread_create(&t2, NULL, r1, data))
        free_on_error(data, 2);

    printf("%i\n", data->num);
    if (pthread_join(t1, NULL));
        free_on_error(data, 3);
    if (pthread_join(t2, NULL));
        free_on_error(data, 3);
    
    printf("%i\n", data->num);
    free_t(data);
}

int main(void)
{
    ex();
}