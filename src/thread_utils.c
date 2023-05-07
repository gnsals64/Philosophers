/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:20:57 by hupa              #+#    #+#             */
/*   Updated: 2023/05/08 02:51:54 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_thread_create(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num - 1)
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
	philo[i].last_eat = ft_get_time();
	if (pthread_create(&tid[i], NULL, thread_route_last, &philo[i]) != 0)
	{
		free(tid);
		ft_free(philo);
		printf("thread_create_error\n");
		return (-1);
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

void	*one(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	ft_msg(&philo[0], "has taken a fork");
	pass_time(philo, philo->arg->time_die);
	ft_msg(&philo[0], "died");
	return (NULL);
}

int	only_one(pthread_t *tid, t_philo *philo)
{

	if (pthread_create(&tid[0], NULL, one, philo) != 0)
	{
		free(tid);
		ft_free(philo);
		printf("thread_create_error\n");
		return (-1);
	}
	pthread_join(tid[0], NULL);
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
