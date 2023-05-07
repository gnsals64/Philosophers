/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:21:02 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/08 02:58:49 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	dine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->fork[philo->left_fork]));
	ft_msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->share->fork[philo->right_fork]));
	ft_msg(philo, "has taken a fork");
	ft_msg(philo, "is eating");
	pthread_mutex_lock(&(philo->share->time));
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(philo->share->time));
	philo->eat_cnt++;
	pass_time(philo, philo->arg->time_eat);
	pthread_mutex_unlock(&(philo->share->fork[philo->right_fork]));
	pthread_mutex_unlock(&(philo->share->fork[philo->left_fork]));
}

void	dine_last(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->fork[philo->right_fork]));
	ft_msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->share->fork[philo->left_fork]));
	ft_msg(philo, "has taken a fork");
	ft_msg(philo, "is eating");
	pthread_mutex_lock(&(philo->share->time));
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(philo->share->time));
	philo->eat_cnt++;
	pass_time(philo, philo->arg->time_eat);
	pthread_mutex_unlock(&(philo->share->fork[philo->left_fork]));
	pthread_mutex_unlock(&(philo->share->fork[philo->right_fork]));
}

void	*thread_route(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	ft_sleep(philo);
	while (1)
	{
		dine(philo);
		if (philo->arg->must_eat != -1)
		{
			if (philo->eat_cnt >= philo->arg->must_eat)
			{
				pthread_mutex_lock(&(philo->share->end));
				philo->share->finish++;
				pthread_mutex_unlock(&(philo->share->end));
				break ;
			}
		}
		ft_sleep_msg(philo);
		if (dine_check_dead(philo) == 1)
			break ;
		ft_msg(philo, "is thinking");
		usleep(100);
	}
	return (NULL);
}

void	*thread_route_last(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	ft_sleep(philo);
	while (1)
	{
		dine_last(philo);
		if (philo->arg->must_eat != -1)
		{
			if (philo->eat_cnt >= philo->arg->must_eat)
			{
				pthread_mutex_lock(&(philo->share->end));
				philo->share->finish++;
				pthread_mutex_unlock(&(philo->share->end));
				break ;
			}
		}
		ft_sleep_msg(philo);
		if (dine_check_dead(philo) == 1)
			break ;
		ft_msg(philo, "is thinking");
		usleep(100);
	}
	return (NULL);
}
