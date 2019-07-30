/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:20:06 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/28 00:33:04 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar_inarray(int *count, char *str, char c);

void	ft_print_line_00(int x, int *count, char *str)
{
	if (x == 1)
		ft_putchar_inarray(count, str, 'o');
	else if (x > 1)
	{
		ft_putchar_inarray(count, str, 'o');
		while (x-- > 2)
			ft_putchar_inarray(count, str, '-');
		ft_putchar_inarray(count, str, 'o');
	}
	ft_putchar_inarray(count, str, '\n');
}

void	ft_print_row_00(int x, int *count, char *str)
{
	if (x == 1)
		ft_putchar_inarray(count, str, '|');
	else if (x > 1)
	{
		ft_putchar_inarray(count, str, '|');
		while (x-- > 2)
			ft_putchar_inarray(count, str, ' ');
		ft_putchar_inarray(count, str, '|');
	}
	ft_putchar_inarray(count, str, '\n');
}

char	*rush_00(int x, int y)
{
	char	*output;
	int		count;

	count = 0;
	output = (char*)malloc(sizeof(*output) * ((x + 1) * y + 1));
	output[(x + 1) * y] = '\0';
	if (y == 1)
		ft_print_line_00(x, &count, output);
	else if (y > 1)
	{
		ft_print_line_00(x, &count, output);
		while (y-- > 2)
		{
			ft_print_row_00(x, &count, output);
		}
		ft_print_line_00(x, &count, output);
	}
	return (output);
}
