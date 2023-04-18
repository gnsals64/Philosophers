/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/18 20:56:08 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	thread_route(void	*arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	while (i < )
	printf("%d", )
}

void	philosopher(t_arg *arg, t_philo *philo)
{
	pthread_t	*tid;
	int			i;

	i = 0;
	tid = (pthread_t)malloc(sizeof(pthread_t) * arg->num);
	if (!tid)
		error_handle("malloc error");
	while (i < arg->num)
	{
		pthread_create(&tid[i], NULL, thread_route, philo);
		i++;
	}
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
