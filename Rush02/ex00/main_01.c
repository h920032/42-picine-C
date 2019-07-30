/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:19:33 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/28 00:28:16 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc - 1 != 2)
		return (0);
	printf("%s", rush_01(ft_atoi(argv[1]), ft_atoi(argv[2])));
	return (0);
}
