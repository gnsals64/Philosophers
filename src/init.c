/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:26:51 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/26 15:07:11 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_init(t_arg *arg, t_philo **philo, t_share *share, char **argv)
{
	memset(arg, 0, sizeof(t_arg));
	init_arg(arg, argv);
	init_share(share, arg);
	init_philo(philo, arg, share);
}

void	init_share(t_share *share, t_arg *arg)
{
	int	i;

	i = 0;
	share->fork = malloc(sizeof(pthread_mutex_t) * arg->num);
	if (!share->fork)
		error_handle("malloc error");
	while (i < arg->num)
	{
		ft_check(pthread_mutex_init(&(share->fork[i]), NULL));
		i++;
	}
	ft_check(pthread_mutex_init(&(share->print), NULL));
	share->time_to_start = ft_get_time();
	share->finish = false;
}

void	init_philo(t_philo **philo, t_arg *arg, t_share *share)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->num);
	if (!(*philo))
		error_handle("malloc error\n");
	while (i < arg->num)
	{
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].id = i;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + arg->num - 1) % arg->num;
		(*philo)[i].last_eat = ft_get_time();
		(*philo)[i].arg = arg;
		(*philo)[i].share = share;
		i++;
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
