/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:39:54 by hunpark           #+#    #+#             */
/*   Updated: 2023/05/08 02:41:08 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_free(t_philo *philo)
{
	free(philo->share->fork);
	free(philo);
	mutex_error_destroy(philo->share, 4);
}

void	mutex_error_destroy(t_share *share, int i)
{
	if (i == 1)
		pthread_mutex_destroy(&(share->print));
	if (i == 2)
	{
		pthread_mutex_destroy(&(share->print));
		pthread_mutex_destroy(&(share->time));
	}
	if (i == 3)
	{
		pthread_mutex_destroy(&(share->print));
		pthread_mutex_destroy(&(share->time));
		pthread_mutex_destroy(&(share->mutex_die));
	}
	if (i == 4)
	{
		pthread_mutex_destroy(&(share->print));
		pthread_mutex_destroy(&(share->time));
		pthread_mutex_destroy(&(share->mutex_die));
		pthread_mutex_destroy(&(share->end));
	}
}
