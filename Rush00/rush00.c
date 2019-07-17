/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:53:44 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/15 14:54:02 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_putchar(char c);

void	ft_print_line(int x)
{
	if (x == 1)
		ft_putchar('o');
	else if (x > 1)
	{
		ft_putchar('o');
		while (x-- > 2)
			ft_putchar('-');
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	ft_print_row(x)
{
	if (x == 1)
		ft_putchar('|');
	else if (x > 1)
	{
		ft_putchar('|');
		while (x-- > 2)
			ft_putchar(' ');
		ft_putchar('|');
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
