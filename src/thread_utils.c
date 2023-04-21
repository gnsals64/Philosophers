/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:20:57 by hupa              #+#    #+#             */
/*   Updated: 2023/04/22 02:22:24 by hupa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	ft_thread_create(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num)
	{
		pthread_create(&tid[i], NULL, thread_route, philo);
		i++;
	}

}

void	ft_thread_join(pthread_t *tid, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->arg->num)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}
