/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:08:03 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/28 01:59:25 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

void	ft_init(int *var)
{
	var[3] = 1;
	var[1] = 1;
	var[2] = 1;
}

void	ft_search(int len, t_rush g_rush[5], int *count, char *input)
{
	int	var[4];

	var[0] = -1;
	while (++var[0] < 5)
	{
		ft_init(var);
		while ((var[1] + 1) * var[2] <= len && var[3])
		{
			while ((var[1] + 1) * var[2] <= len && var[3])
			{
				if (ft_strcmp(input, g_rush[var[0]].r(var[1], var[2])) == 0)
				{
					g_rush[var[0]].x = var[1];
					g_rush[var[0]].y = var[2];
					g_rush[var[0]].s = YES;
					*count = *count + 1;
					var[3] = 0;
				}
				var[2]++;
			}
			var[2] = 1;
			var[1]++;
		}
	}
}

int		ft_print_one(t_rush g_rush[5])
{
	int	c;

	c = 0;
	while (c < 5)
	{
		if (g_rush[c].s == YES)
		{
			ft_putchar('[');
			ft_putstr(g_rush[c].one);
			ft_putchar(']');
			ft_putchar(' ');
			ft_putchar('[');
			ft_putnbr(g_rush[c].x);
			ft_putchar(']');
			ft_putchar(' ');
			ft_putchar('[');
			ft_putnbr(g_rush[c].y);
			ft_putchar(']');
			return (1);
		}
		c++;
	}
	return (0);
}

void	ft_print_two(t_rush g_rush[5])
{
	int	is_find;
	int	c;

	is_find = 0;
	c = 0;
	while (c < 5)
	{
		if (g_rush[c].s == YES)
		{
			if (is_find)
				ft_putstr(" || ");
			is_find = 1;
			ft_putchar('[');
			ft_putstr(g_rush[c].two);
			ft_putstr("] [");
			ft_putnbr(g_rush[c].x);
			ft_putstr("] [");
			ft_putnbr(g_rush[c].y);
			ft_putchar(']');
		}
		c++;
	}
}

int		main(void)
{
	int		len;
	int		count;
	char	*input;

	input = ft_import_stdin();
	len = ft_strlen(input);
	count = 0;
	ft_search(len, g_rush, &count, input);
	if (count == 1)
	{
		if (ft_print_one(g_rush))
			return (0);
	}
	else if (count > 1)
	{
		ft_print_two(g_rush);
		return (0);
	}
	ft_putstr("aucune\n");
	return (0);
}
