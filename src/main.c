/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:35:56 by hunpark           #+#    #+#             */
/*   Updated: 2023/04/14 17:02:11 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;

	if (argc != 5 && argc != 6)
		exit(1);
	arg = (t_arg *)malloc(sizeof(arg));
	if (!arg)
		exit(1);
	memset(arg, 0, sizeof(t_arg));
	set_arg(arg, argv);
}
