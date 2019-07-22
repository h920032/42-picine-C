/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:36:34 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/21 17:26:13 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_header2.h"
#include <stdio.h>

int	main(int argv, char **argc)
{
	int	table[9][9];
	int	mark[9][9][9];
	int	is_find;
	int	count_one;
	int	count_two;
	int	count_three;

	count_one = 0;
	while (count_one < 9)
	{
		count_two = 0;
		while (count_two < 9)
		{
			count_three = 0;
			while (count_three < 9)
			{
				mark[count_one][count_two][count_three] = 0;
				count_three++;
			}
			count_two++;
		}
		count_one++;
	}
	is_find = 0;
	if (argv - 1 != 9)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_table_trans(argc, table))
	{	
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_input_test(table))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_sudoku_rec(table, &is_find, mark, 1);
	return (0);
}
