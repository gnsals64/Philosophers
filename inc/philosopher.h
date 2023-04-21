/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:37:08 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/22 02:22:18 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_arg
{
	int				num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	pthread_mutex_t	mutex;
}	t_arg;

typedef struct s_philo
{
	int				cnt;
	int				id;
	int				status;
	t_arg			*arg;
}	t_philo;

//ain
void	*thread_route(void *arg);
void	philosopher(t_arg *arg, t_philo *philo);

// init
void	ft_init(t_arg *arg, t_philo **philo, char **argv);
void	init_philo(t_philo **philo, t_arg *arg);
void	init_arg(t_arg *arg, char **argv);

//utils
int		ft_atoi(const char *s);
void	error_handle(char *str);
void	ft_check(int a);

// thread_utils
void	ft_thread_create(pthread_t *tid, t_philo *philo);
void	ft_thread_join(pthread_t *tid, t_philo *philo);


#endif
