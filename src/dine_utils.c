/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:42:33 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/08 01:49:07 by hupa             ###   ########.fr       */
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
	while (1)
	{
		now = ft_get_time();
		if ((now - start) >= time)
			break ;
		pthread_mutex_lock(&(philo->share->mutex_die));
		if (philo->share->dead == true)
		{
			pthread_mutex_unlock(&(philo->share->mutex_die));
			break ;
		}
		pthread_mutex_unlock(&(philo->share->mutex_die));
		usleep(100);
	}
}

void	ft_sleep(t_philo *philo)
{
	if (philo->id % 2)
		usleep(1000);
}

void	ft_sleep_msg(t_philo *philo)
{
	ft_msg(philo, "is sleeping");
	pass_time(philo, philo->arg->time_sleep);
}

int	dine_check_dead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->mutex_die));
	if (philo->share->dead == true)
	{
		pthread_mutex_unlock(&(philo->share->mutex_die));
		return (1);
	}
	pthread_mutex_unlock(&(philo->share->mutex_die));
	return (0);
}
