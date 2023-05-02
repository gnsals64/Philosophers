/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:23:42 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/02 20:11:07 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	must_eat_run(t_philo *philo)
{
	if (philo->arg->must_eat != -1)
	{
		pthread_mutex_lock(&(philo->share->end));
		if (philo->share->finish == philo->arg->num)
		{
			pthread_mutex_lock(&(philo->share->mutex_die));
			philo->share->dead = true;
			pthread_mutex_unlock(&(philo->share->mutex_die));
			pthread_mutex_unlock(&(philo->share->end));
			return (1);
		}
		pthread_mutex_unlock(&(philo->share->end));
	}
	return (0);
}

int	check_die(t_philo *philo, int i, long now)
{
	if (must_eat_run(philo) == 1)
		return (1);
	pthread_mutex_lock(&(philo->share->time));
	if ((now - philo[i].last_eat > philo->arg->time_die))
	{
		pthread_mutex_lock(&(philo->share->mutex_die));
		philo->share->dead = true;
		pthread_mutex_unlock(&(philo->share->mutex_die));
		pthread_mutex_lock(&(philo->share->print));
		printf("%lu %d died\n",
			(now - philo->share->time_to_start), philo[i].id);
		pthread_mutex_unlock(&(philo->share->print));
		pthread_mutex_unlock(&(philo->share->time));
		return (1);
	}
	pthread_mutex_unlock(&(philo->share->time));
	usleep(1000);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	long	now;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->arg->num)
		{
			now = ft_get_time();
			if (check_die(philo, i, now) == 1)
				break ;
			i++;
		}
		pthread_mutex_lock(&(philo->share->mutex_die));
		if (philo->share->dead == true)
		{
			pthread_mutex_unlock(&(philo->share->mutex_die));
			break ;
		}
		pthread_mutex_unlock(&(philo->share->mutex_die));
		usleep(1000);
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
	pthread_join(monitor_thread, NULL);
	return (0);
}
