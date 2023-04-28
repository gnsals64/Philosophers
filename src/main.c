/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 17:09:10 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	philosopher(t_arg *arg, t_philo *philo)
{
	pthread_t	*tid;

	tid = (pthread_t *)malloc(sizeof(pthread_t) * arg->num);
	if (!tid)
	{
		ft_free(philo);
		error_handle("malloc error");
	}
	ft_thread_create(tid, philo);
	monitor_thread(tid, philo);
	ft_thread_join(tid, philo);
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_share		share;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		error_handle("usage : ./philosopher 1 2 3 4 (5)\n");
	ft_init(&arg, &philo, &share, argv);
	philosopher(&arg, philo);
}
