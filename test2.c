#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				mails;
}	t_mutex;

void	*routine(void *arg)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)arg;
	for (int i=0;i<1000000;i++){
		pthread_mutex_lock(&mutex->mutex);
		mutex->mails++;
		pthread_mutex_unlock(&mutex->mutex);
	}
}

int	main()
{
	pthread_t	p1, p2;
	t_mutex		mutex;

	mutex.mails = 0;
	pthread_mutex_init(&mutex.mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, &mutex) != 0)
		return 1;
	if (pthread_create(&p2, NULL, &routine, &mutex) != 0)
		return 2;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;
	pthread_mutex_destroy(&mutex.mutex);
	printf("Number of mails : %d\n", mutex.mails);
	return 0;
}
