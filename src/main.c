/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/08 02:50:05 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_init(t_arg *arg, t_philo **philo, t_share *share, char **argv)
{
	memset(arg, 0, sizeof(t_arg));
	if (check_argv(argv) == -1)
		return (-1);
	init_arg(arg, argv);
	if (init_share(share, arg) == -1)
		return (-1);
	if (init_philo(philo, arg, share) == -1)
		return (-1);
	return (0);
}

int	philosopher(t_arg *arg, t_philo *philo)
{
	pthread_t	*tid;

	tid = (pthread_t *)malloc(sizeof(pthread_t) * arg->num);
	if (!tid)
	{
		ft_free(philo);
		return (-1);
	}
	if (arg->num != 1)
	{
		if (ft_thread_create(tid, philo) == -1)
			return (-1);
		if (monitor_thread(tid, philo) == -1)
			return (-1);
		if (ft_thread_join(tid, philo) == -1)
			return (-1);
	}
	else
	{
		if (only_one(tid, philo) == -1)
			return (-1);
	}
	free(tid);
	ft_free(philo);
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
