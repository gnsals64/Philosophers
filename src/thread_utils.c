/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:20:57 by hupa              #+#    #+#             */
/*   Updated: 2023/04/28 17:09:17 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_thread_create(pthread_t *tid, t_philo *philo)
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
			error_handle("thread_create_error");
		}
		usleep(10);
		i++;
	}
	usleep(1000);
	if (philo->share->finish == true)
		exit(1);
}

void	ft_thread_join(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num)
	{
		if (pthread_join(tid[i], NULL) != 0)
		{
			free(tid);
			ft_free(philo);
			error_handle("thread_join_error");
		}
		i++;
	}
}

void	ft_msg(t_philo *philo, char *msg)
{
	long	now;

	now = ft_get_time();
	if (philo->share->finish != true)
	{
		pthread_mutex_lock(&(philo->share->print));
		printf("%lums    %d    %s\n",
			(now - philo->share->time_to_start), philo->id, msg);
		pthread_mutex_unlock(&(philo->share->print));
	}
}
