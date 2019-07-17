/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:46:10 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/15 23:43:53 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_width_counter(int size)
{
	if (size == 1)
	{
		return (7);
	}
	else
	{
		return ((size / 2 + 1) * 2 + ft_width_counter(size - 1) + (size + 2) * 2);
	}
}

void	ft_print_fill(int type, int nb)
{
	char	print_type;

	if (type == 1)
		print_type = ' ';
	else if (type == 2)
		print_type = '*';
	while (nb > 0)
	{
		ft_putchar(print_type);
		nb--;
	}
}

void	ft_sastantua_recursive(int shift, int size)
{
	int	count_one;

	count_one = 1;
	if (size == 1)
	{
		while (count_one <= size + 2)
		{
			ft_print_fill(1, shift / 2 - count_one);
			ft_putchar(47);
			ft_print_fill(2, (count_one - 1) * 2 + 1);
			ft_putchar(92);
			ft_putchar('\n');
			count_one++;
		}
	}
	else
	{
		ft_sastantua_recursive(shift, size - 1);
		while (count_one <= size + 2)
		{
			ft_print_fill(1, shift / 2 - count_one - ft_width_counter(size) / 2 + size + 2);
			ft_putchar(47);
			ft_print_fill(2, (ft_width_counter(size) / 2 + count_one - size - 3) * 2 + 1);
			ft_putchar(92);
			ft_putchar('\n');
			count_one++;
		}
	}
}

void	sastantua(int size)
{
	int	count_one;

	count_one = 1;
	ft_sastantua_recursive(ft_width_counter(size), size - 1);
	if (size > 0)
	{
		while (count_one <= size + 2)
		{
			ft_print_fill(1, size + 2 - count_one);
			ft_putchar(47);
			ft_print_fill(2, (ft_width_counter(size) / 2 + count_one - size - 3) * 2 + 1);
			ft_putchar(92);
			ft_putchar('\n');
			count_one++;
		}
		
	}
}
