/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:01:55 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/14 10:02:28 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int x)
{
	if (x == 1)
		ft_putchar(47);
	else if (x > 1)
	{
		ft_putchar(47);
		while (x-- > 2)
			ft_putchar('*');
		ft_putchar(92);
	}
	ft_putchar('\n');
}

void	ft_print_endline(int x)
{
	if (x == 1)
		ft_putchar(92);
	else if (x > 1)
	{
		ft_putchar(92);
		while (x-- > 2)
			ft_putchar('*');
		ft_putchar(47);
	}
	ft_putchar('\n');
}

void	ft_print_row(x)
{
	if (x == 1)
		ft_putchar('*');
	else if (x > 1)
	{
		ft_putchar('*');
		while (x-- > 2)
			ft_putchar(' ');
		ft_putchar('*');
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
		ft_print_endline(x);
	}
}
