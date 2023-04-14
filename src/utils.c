/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:00:59 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/14 17:02:16 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_atoi(const char *s)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (((s[i] >= 9 && s[i] <= 13) || s[i] == 32) && s[i])
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (sign * res);
}

void	set_arg(t_arg *arg, char **argv)
{
	arg->num = ft_atoi(argv[1]);
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		arg->must_eat = ft_atoi(argv[5]);
	if (arg->num < 0 || arg->time_die < 0 || arg->time_eat < 0
		|| arg->time_sleep < 0 || arg->must_eat < 0)
		exit(1);
}
