/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:01:55 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/28 00:41:34 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar_inarray(int *count, char *str, char c);

void	ft_print_line_01(int x, int *count, char *str)
{
	if (x == 1)
		ft_putchar_inarray(count, str, 47);
	else if (x > 1)
	{
		ft_putchar_inarray(count, str, 47);
		while (x-- > 2)
			ft_putchar_inarray(count, str, '*');
		ft_putchar_inarray(count, str, 92);
	}
	ft_putchar_inarray(count, str, '\n');
}

void	ft_print_endline_01(int x, int *count, char *str)
{
	if (x == 1)
		ft_putchar_inarray(count, str, 92);
	else if (x > 1)
	{
		ft_putchar_inarray(count, str, 92);
		while (x-- > 2)
			ft_putchar_inarray(count, str, '*');
		ft_putchar_inarray(count, str, 47);
	}
	ft_putchar_inarray(count, str, '\n');
}

void	ft_print_row_01(int x, int *count, char *str)
{
	if (x == 1)
		ft_putchar_inarray(count, str, '*');
	else if (x > 1)
	{
		ft_putchar_inarray(count, str, '*');
		while (x-- > 2)
			ft_putchar_inarray(count, str, ' ');
		ft_putchar_inarray(count, str, '*');
	}
	ft_putchar_inarray(count, str, '\n');
}

char	*rush_01(int x, int y)
{
	char	*output;
	int		count;

	count = 0;
	output = (char*)malloc(sizeof(*output) * ((x + 1) * y + 1));
	output[(x + 1) * y] = '\0';
	if (y == 1)
		ft_print_line_01(x, &count, output);
	else if (y > 1)
	{
		ft_print_line_01(x, &count, output);
		while (y-- > 2)
		{
			ft_print_row_01(x, &count, output);
		}
		ft_print_endline_01(x, &count, output);
	}
	return (output);
}
