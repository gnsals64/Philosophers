/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:21:02 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 02:24:03 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	dine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->fork[philo->left_fork]));
	ft_msg(philo, "has taken a fork");
	if (philo->arg->num != 1)
	{
		pthread_mutex_lock(&(philo->share->fork[philo->right_fork]));
		ft_msg(philo, "has taken a fork");
		ft_msg(philo, "is eating");
		philo->last_eat = ft_get_time();
		philo->eat_cnt++;
		usleep(philo->arg->time_eat * 1000);
		pthread_mutex_unlock(&(philo->share->fork[philo->right_fork]));
	}
	pthread_mutex_unlock(&(philo->share->fork[philo->left_fork]));
}

void	*thread_route(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (1)
	{
		dine(philo);
		ft_msg(philo, "is sleeping");
		usleep(philo->arg->time_sleep * 1000);
		ft_msg(philo, "is thinking");
	}
	return (NULL);
}
