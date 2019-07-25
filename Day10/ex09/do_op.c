/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:34:05 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 19:10:33 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include "ft_header_two.h"
#include "ft_header_three.h"
#include "ft_opp.h"

int		main(int argv, char **argc)
{
	int	count;

	count = -1;
	if (argv - 1 != 3)
		return (0);
	if (argc[2][1] != '\0')
		count = 6;
	while (count++ < 5)
	{
		if (*argc[2] == g_opptab[count].symbol[0])
		{
			if (count == 3 && ft_atoi_me(argc[3]) == 0)
				ft_putstr_me("Stop : division by zero");
			else if (count == 4 && ft_atoi_me(argc[3]) == 0)
				ft_putstr_me("Stop : modulo by zero");
			else if (count < 6)
				ft_putnbr_me(g_opptab[count].f(ft_atoi_me(argc[1]),
							ft_atoi_me(argc[3])));
			ft_putchar_me('\n');
			return (0);
		}
	}
	ft_putstr_me("error : only [ + - * / % ] are accepted.\n");
	return (0);
}
