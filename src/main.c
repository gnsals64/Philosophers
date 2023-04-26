/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/26 15:07:10 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_msg(t_philo *philo, char *msg)
{
	long	now;

	now = ft_get_time();
	pthread_mutex_lock(&(philo->share->print));
	printf("%lu %d %s\n", now, philo->id, msg);
	pthread_mutex_unlock(&(philo->share->print));
}

void	dine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->share->fork[philo->left_fork]));
	ft_msg(philo, "has taken a fork");
	if (philo->arg->num != 1)
	{
		pthread_mutex_lock(&(philo->share->fork[philo->right_fork]));
		ft_msg(philo, "has taken a fork");
		ft_msg(philo, "is eating");
		philo->last_eat = ft_get_time();
		philo->eat_cnt++;
		pthread_mutex_unlock(&(philo->share->fork[philo->right_fork]));
	}
	pthread_mutex_unlock(&(philo->share->fork[philo->left_fork]));
}

t_bool	is_die(t_philo *philo)
{
	if (philo->share->finish == true)
		return (false);
	return (true);
}

void	*thread_route(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(100);
	while (philo->share->finish != true)
	{
		dine(philo);
	}
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
	t_share		share;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		error_handle("usage : ./philosopher 1 2 3 4 (5)\n");
	ft_init(&arg, &philo, &share, argv);
	philosopher(&arg, philo);
}
