/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 19:34:26 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	philosopher(t_arg *arg, t_philo *philo)
{
	pthread_t	*tid;

	tid = (pthread_t *)malloc(sizeof(pthread_t) * arg->num);
	if (!tid)
	{
		ft_free(philo);
		return (-1);
	}
	if (ft_thread_create(tid, philo) == -1)
		return (-1);
	if (monitor_thread(tid, philo) == -1)
		return (-1);
	if (ft_thread_join(tid, philo) == -1)
		return (-1);
	free(tid);
	free(philo);
	free(philo->share->fork);
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_share		share;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
	{
		printf("usage : ./philosopher 1 2 3 4 (5)\n");
		return (1);
	}
	if (ft_init(&arg, &philo, &share, argv) == -1)
	{
		printf("init error\n");
		return (1);
	}
	if (philosopher(&arg, philo) == -1)
		return (1);
	return (0);
}
