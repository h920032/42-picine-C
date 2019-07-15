/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:05:16 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/14 10:07:22 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x)
{
	if (x == 1)
		ft_putchar('A');
	else if (x > 1)
	{
		ft_putchar('A');
		while (x-- > 2)
			ft_putchar('B');
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_print_row(x)
{
	if (x == 1)
		ft_putchar('B');
	else if (x > 1)
	{
		ft_putchar('B');
		while (x-- > 2)
			ft_putchar(' ');
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (y == 1)
		ft_print_line(x);
	else if (y > 1)
	{
		ft_print_line(x);
		while (y-- > 2)
		{
			ft_print_row(x);
		}
		ft_print_line(x);
	}
}
