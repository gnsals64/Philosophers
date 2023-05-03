/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:19:32 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/03 21:24:11 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	fork_destroy_if_fail(t_share *share, t_arg *arg, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&share->fork[j]);
		j++;
	}
}

int	init_share(t_share *share, t_arg *arg)
{
	int	i;

	i = 0;
	share->fork = malloc(sizeof(pthread_mutex_t) * arg->num);
	if (!share->fork)
		return (-1);
	while (i < arg->num)
	{
		if (pthread_mutex_init(&(share->fork[i]), NULL) != 0)
		{
			fork_destroy_if_fail(share, arg, i);
			free(share->fork);
			printf("mutex_init_error\n");
			return (-1);
		}
		i++;
	}
	if (mutex_init(share) == -1)
	{
		free(share->fork);
		printf("mutex_init_error\n");
		return (-1);
	}
	return (0);
}
