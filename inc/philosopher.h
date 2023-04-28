/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:37:08 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/28 16:46:56 by hunpark          ###   ########.fr       */
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

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_arg
{
	int				num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
}	t_arg;

typedef struct s_share
{
	long			time_to_start;
	t_bool			finish;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}	t_share;

typedef struct s_philo
{
	int				eat_cnt;
	int				id;
	long			last_eat;
	int				left_fork;
	int				right_fork;
	t_arg			*arg;
	t_share			*share;
}	t_philo;

//main
void	*thread_route(void *arg);
void	philosopher(t_arg *arg, t_philo *philo);

// init
void	ft_init(t_arg *arg, t_philo **philo, t_share *share, char **argv);
void	init_philo(t_philo **philo, t_arg *arg, t_share *share);
void	init_arg(t_arg *arg, char **argv);
void	init_share(t_share *share, t_arg *arg);

//utils
int		ft_atoi(const char *s);
void	error_handle(char *str);
long	ft_get_time(void);
void	ft_free(t_philo *philo);

// thread_utils
void	ft_thread_create(pthread_t *tid, t_philo *philo);
void	ft_thread_join(pthread_t *tid, t_philo *philo);
void	ft_msg(t_philo *philo, char *msg);

// dine
void	dine(t_philo *philo);
void	*thread_route(void *arg);

//monitor
void	*monitor(void *arg);
void	monitor_thread(pthread_t *tid, t_philo *philo);

#endif
