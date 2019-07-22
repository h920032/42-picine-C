/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:38:52 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/21 17:25:11 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_HEADER_H
# define FT_RUSH_HEADER_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		ptr_count;
	char	temp;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while (temp != '\0')
	{
		ft_putchar(temp);
		ptr_count++;
		temp = *(str + ptr_count);
	}
}

int		ft_table_trans(char **t_src, int table[9][9])
{
	int	count;
	int	count_two;

	count = 1;
	while (count <= 9)
	{
		count_two = 0;
		while (t_src[count][count_two] != '\0')
		{
			if (t_src[count][count_two] <= '9' && t_src[count][count_two] >= '0')
				table[count - 1][count_two] = t_src[count][count_two] - 48;
			else if (t_src[count][count_two] == '.')
				table[count - 1][count_two] = 0;
			else
				return (0);
			count_two++;
		}
		count++;
	}
	return (1);
}

void	ft_print_result(int src[9][9])
{
	int count_one;
	int count_two;
	
	count_one = 0;
	while (count_one < 9)
	{
		count_two = 1;
		ft_putchar(src[count_one][0] + 48);
		while (count_two < 9)
		{
			ft_putchar(' ');
			ft_putchar(src[count_one][count_two] + 48);
			count_two++;
		}
		ft_putchar('\n');
		count_one++;
	}
}

void	ft_table_copy(int src[9][9], int cpy[9][9])
{
	int	count_one;
	int	count_two;

	count_one = 0;
	while (count_one < 9)
	{
		count_two = 0;
		while (count_two < 9)
		{
			cpy[count_one][count_two] = src[count_one][count_two];
			count_two++;
		}
		count_one++;
	}
}

void	ft_mark_copy(int src[9][9][9], int cpy[9][9][9])
{
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
				cpy[count_one][count_two][count_three] = src[count_one][count_two][count_three];
				count_three++;
			}
			count_two++;
		}
		count_one++;
	}
}

int		ft_set_range(int d)
{
	if (d >= 0 &&  d <=2)
		return (3);
	else if (d >= 3 && d <= 5)
		return (6);
	else if (d >= 6 && d <= 8)
		return (9);
	return (0);
}

int		ft_set_number(int src[9][9], int c, int r, int d)
{
	int	count_one;
	int	count_two;

	count_one = ft_set_range(c) - 3;
	while (count_one < ft_set_range(c))
	{
		count_two = ft_set_range(r) - 3;
		while (count_two < ft_set_range(r))
		{
			if (d == src[count_one][count_two])
				return (0);
			count_two++;
		}
		count_one++;
	}
	count_one = 0;
	while (count_one < 9)
	{
		if (d == src[count_one][r])
			return (0);
		count_one++;
	}
	count_two = 0;
	while (count_two < 9)
	{
		if (d == src[c][count_two])
			return (0);
		count_two++;
	}
	return (1);
}

int		ft_count(int src[9][9])
{
	int	count;
	int	count_one;
	int	count_two;

	count = 0;
	count_one = 0;
	while (count_one < 9)
	{
		count_two = 0;
		while (count_two < 9)
		{
			if (src[count_one][count_two] != 0)
				count++;
			count_two++;
		}
		count_one++;
	}
	return (count);
}

int		ft_input_test(int src[9][9])
{
	int	one;
	int	two;
	int	temp;

	one = 0;
	while (one < 9)
	{
		two = 0;
		while (two < 9)
		{
			if (src[one][two] != 0)
			{
				temp = src[one][two];
				src[one][two] = 0;
				if (ft_set_number(src, one, two, temp))
					src[one][two] = temp;
				else
					return (0);
			}
			two++;
		}
		one++;
	}
	return (1);
}

void	ft_sudoku_rec(int src[9][9], int *is_find, int mark[9][9][9], int first)
{
	int	next[9][9];
	int	new_mark[9][9][9];
	int count_two;
	int	count_one;
	int	nbr;
	int	can_put;
	int	has_ans;

	count_one = 0;
	can_put = 0;
	has_ans = 0;
	nbr = 1;
	ft_mark_copy(mark, new_mark);
	if (*is_find)
		return ;
	while (count_one < 9)
	{
		count_two = 0;
		while (count_two < 9)
		{
			if (src[count_one][count_two] == 0)
			{
				can_put = 1;
				nbr = 1;
				has_ans = 0;
				while (nbr <= 9)
				{
					if (mark[count_one][count_two][nbr - 1] != 1 && ft_set_number
							(src, count_one, count_two, nbr))
					{
						has_ans = 1;
						//ft_putchar(nbr + 48);
						ft_table_copy(src, next);
						next[count_one][count_two] = nbr;
						ft_sudoku_rec(next, is_find, new_mark, 0);
						if (*is_find)
							return ;
						else
							new_mark[count_one][count_two][nbr - 1] = 1;
					}
					else if (ft_set_number(src, count_one, count_two, nbr) == 0)
					{
						new_mark[count_one][count_two][nbr - 1] = 1;
					}
					nbr++;
				}
				if (!has_ans)
					return ;
			}
			count_two++;
		}
		count_one++;
	}
	if (!can_put)
	{
		ft_print_result(src);
		*is_find = 1;
		return ;
	}
}

#endif
