#include "./inc/philosopher.h"
#include <limits.h>

int	main()
{
	struct timeval	time;
	struct timeval	time2;
	long			diff_sec;
	long			diff_usec;
	long			diff_time;


	gettimeofday(&time, NULL);
	usleep(1500 * 1000);
	gettimeofday(&time2, NULL);

	printf("time2_usec : %lu\n", (long)time2.tv_usec);
	printf("time1_usec : %lu\n", (long)time.tv_usec);
	diff_sec = time2.tv_sec - time.tv_sec;
	diff_usec = time2.tv_usec - time.tv_usec;
	diff_time = diff_sec * 1000 + (diff_usec / 1000);
	printf("diff_sec : %ld\n", diff_sec);
	printf("diff_usec : %ld\n", diff_usec);
	printf("diff_time : %ld\n", diff_time);
}
