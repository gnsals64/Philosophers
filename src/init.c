/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:26:51 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/18 20:56:08 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_init(t_arg *arg, t_philo **philo, char **argv)
{
	memset(arg, 0, sizeof(t_arg));
	init_arg(arg, argv);
	init_philo(arg, philo);
}

void	init_philo(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * arg->num);
	if (!(*philo))
		error_handle("malloc error\n");
	while (i < arg->num)
	{

	}
}

void	init_arg(t_arg *arg, char **argv)
{
	arg->num = ft_atoi(argv[1]);
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		arg->must_eat = ft_atoi(argv[5]);
	else
		arg->must_eat = -1;
	if (arg->num < 0 || arg->time_die < 0 || arg->time_eat < 0
		|| arg->time_sleep < 0)
		error_handle("error\n");
}
