/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/18 20:27:51 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_philo		*philo;

	if (argc != 5 && argc != 6)
		error_handle("usage : ./philosopher 1 2 3 4 (5)\n");
	ft_init(&arg, &philo, argv);
}
