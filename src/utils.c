/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:00:59 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/26 15:07:11 by hunpark          ###   ########.fr       */
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
	while ((s[i] >= 48 && s[i] <= 57) && s[i])
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	return (sign * res);
}

void	error_handle(char *str)
{
	printf("%s", str);
	exit(1);
}

void	ft_check(int a)
{
	if (a == 0)
		return ;
	exit(1);
}

long	ft_get_time(void)
{
	struct timeval	start_time;
	struct timeval	end_time;
	long			diff_sec;
	long			diff_usec;

	gettimeofday(&start_time, NULL);
	gettimeofday(&end_time, NULL);
	diff_sec = end_time.tv_sec - start_time.tv_sec;
	diff_usec = end_time.tv_usec - start_time.tv_usec;
	return (diff_sec * 1000 + (diff_usec / 1000));
}
