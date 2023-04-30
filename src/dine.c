/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:21:02 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/30 01:33:00 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	pass_time(t_philo *philo, long time)
{
	long	now;
	long	start;

	start = ft_get_time();
	if (time == 0)
		return ;
	while (philo->share->finish != true)
	{
		now = ft_get_time();
		if ((now - start) >= time)
			break ;
		if (now - philo->last_eat > philo->arg->time_die)
		{
			ft_msg(philo, "is die");
			philo->share->finish = true;
		}
		usleep(100);
	}
}

void	dine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->fork[philo->left_fork]));
	ft_msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->share->fork[philo->right_fork]));
	ft_msg(philo, "has taken a fork");
	ft_msg(philo, "is eating");
	philo->last_eat = ft_get_time();
	philo->eat_cnt++;
	pass_time(philo, philo->arg->time_eat);
	pthread_mutex_unlock(&(philo->share->fork[philo->right_fork]));
	pthread_mutex_unlock(&(philo->share->fork[philo->left_fork]));
}

void	*thread_route(void *arg)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (philo->share->finish != true)
	{
		dine(philo);
		if (philo->arg->must_eat != -1)
		{
			if (philo->eat_cnt >= philo->arg->must_eat)
				break ;
		}
		ft_msg(philo, "is sleeping");
		pass_time(philo, philo->arg->time_sleep);
		if (philo->share->finish == true)
			break ;
		ft_msg(philo, "is thinking");
	}
	return (NULL);
}
