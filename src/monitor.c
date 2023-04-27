/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:23:42 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 02:24:43 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

// void	*monitor(void *arg)
// {
// 	t_philo	*philo;
// 	philo = (t_philo *)arg;

// 	while (1)
// 	{

// 	}
// }

// void	monitor_tread(pthread_t *tid, t_philo *philo)
// {
// 	pthread_t	monitor_thread;

// 	if (pthread_create(&monitor_thread, NULL, monitor, philo) != 0)
// 	{
// 		free(tid);
// 		ft_free(philo);
// 		error_handle("thread_create_error");
// 	}
// }
