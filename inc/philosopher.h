/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:37:08 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/18 20:56:10 by hunpark          ###   ########.fr       */
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
	int	num;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
}	t_arg;

typedef struct s_philo
{
	int				cnt;
	int				name;
	pthread_mutex_t	mutex;
	t_arg			*arg;
}	t_philo;

// init
void	ft_init(t_arg *arg, t_philo **philo, char **argv);
void	init_philo(t_philo **philo, t_arg *arg);
void	init_arg(t_arg *arg, char **argv);

//utils
int		ft_atoi(const char *s);
void	error_handle(char *str);
void	ft_check(int a);

#endif
