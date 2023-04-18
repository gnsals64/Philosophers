#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	len = strlen(s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	memcpy(tmp, s, len);
	tmp[len] = 0;
	return (tmp);
}

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				g_number;
	char			*name;
}	t_mutex;

void	print_index_loop(t_mutex *mutex, int max)
{
	int i;

	i = 0;

	pthread_mutex_lock(&mutex->mutex);
	while (i < 5)
	{
		mutex->g_number++;
		printf("[%s] %d\n", mutex->name, mutex->g_number);
		usleep(1000 * 1000);
		i++;
	}
	pthread_mutex_unlock(&mutex->mutex);
}

void	*thread_routine(void *mutex)
{
	t_mutex	*philo;

	philo = (t_mutex *)mutex;
	print_index_loop(philo, 5);
	return (NULL);
}

int main()
{
	pthread_t	tid1;
	pthread_t	tid2;
	t_mutex		mutex;
	int			join_res;

	mutex.g_number = 0;
	if (pthread_mutex_init(&(mutex.mutex), NULL) != 0)
	{
		printf("fail to init mutex\n");
		exit(1);
	}
	pthread_mutex_lock(&mutex.mutex);
	mutex.name = ft_strdup("thread1");

	pthread_create(&tid1, NULL, thread_routine, &mutex);
	pthread_mutex_unlock(&mutex.mutex);

	pthread_create(&tid2, NULL, thread_routine, &mutex);
	free(mutex.name);
	mutex.name = ft_strdup("thread2");

	join_res = pthread_join(tid1, NULL);
	join_res = pthread_join(tid2, NULL);
	printf("join result: %d\n", join_res);
}
