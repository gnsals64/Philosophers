/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:20:57 by hupa              #+#    #+#             */
/*   Updated: 2023/05/02 19:48:36 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_thread_create(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num)
	{
		philo[i].last_eat = ft_get_time();
		if (pthread_create(&tid[i], NULL, thread_route, &philo[i]) != 0)
		{
			free(tid);
			ft_free(philo);
			printf("thread_create_error\n");
			return (-1);
		}
		usleep(10);
		i++;
	}
	return (0);
}

int	ft_thread_join(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num)
	{
		if (pthread_join(tid[i], NULL) != 0)
		{
			free(tid);
			ft_free(philo);
			printf("thread_join_error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_msg(t_philo *philo, char *msg)
{
	long	now;

	pthread_mutex_lock(&(philo->share->print));
	pthread_mutex_lock(&(philo->share->mutex_die));
	if (philo->share->dead != true)
	{
		now = ft_get_time();
		printf("%lu %d %s\n",
			(now - philo->share->time_to_start), philo->id, msg);
	}
	pthread_mutex_unlock(&(philo->share->mutex_die));
	pthread_mutex_unlock(&(philo->share->print));
}
