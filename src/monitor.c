/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:23:42 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 19:41:21 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	long	now;

	philo = (t_philo *)arg;
	while (philo->share->finish != true)
	{
		i = 0;
		while (i < philo->arg->num)
		{
			now = ft_get_time();
			if (now - philo[i].last_eat > philo->arg->time_die)
			{
				philo->share->finish = true;
				pthread_mutex_lock(&(philo->share->print));
				printf("%lu %d died\n",
					(now - philo->share->time_to_start), philo[i].id);
				pthread_mutex_unlock(&(philo->share->print));
				break ;
			}
			i++;
		}
		usleep(10);
	}
	return (NULL);
}

int	monitor_thread(pthread_t *tid, t_philo *philo)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, monitor, philo) != 0)
	{
		free(tid);
		ft_free(philo);
		printf("thread_create_error\n");
		return (-1);
	}
	return (0);
}
