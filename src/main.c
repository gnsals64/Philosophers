/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/22 02:21:48 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	*thread_route(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->arg->mutex));
	while (i < philo->arg->num)
	{
		printf("%d\n", i);
		i++;
	}
	printf("\n");
	pthread_mutex_unlock(&(philo->arg->mutex));
	return (NULL);
}

void	philosopher(t_arg *arg, t_philo *philo)
{
	pthread_t	*tid;

	tid = (pthread_t *)malloc(sizeof(pthread_t) * arg->num);
	if (!tid)
		error_handle("malloc error");
	ft_thread_create(tid, philo);
	ft_thread_join(tid, philo);
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		error_handle("usage : ./philosopher 1 2 3 4 (5)\n");
	ft_init(&arg, &philo, argv);
	philosopher(&arg, philo);
}
