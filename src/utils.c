/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:00:59 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/08 01:46:47 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	ft_atoi(const char *s)
{
	size_t	i;
	long	res;

	i = 0;
	res = 0;
	while ((s[i] >= 48 && s[i] <= 57) && s[i])
	{
		res = res * 10 + s[i] - 48;
		i++;
	}
	if (i > 10)
		return (0);
	if (res > 214748647)
		return (0);
	return ((int)res);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}
