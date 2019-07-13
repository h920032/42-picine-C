/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:51:30 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/13 12:29:33 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_array_copy(int origin[9][8], int copy[9][8], int n)
{
	int count_one;
	int	count_two;

	count_one = 0;
	while (count_one < n + 1)
	{
		count_two = 0;
		while (count_two < n)
		{
			copy[count_one][count_two] = origin[count_one][count_two];
			count_two++;
		}
		count_one++;
	}
}

void	ft_write_in(int place[9][8], int l, int n)
{
	if (l <= 7 && n <= 7 && l >= 0 && n >= 0)
	{
		place[l][n] = 1;
	}
}

void	ft_putchess(int place[9][8], int l, int n)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		ft_write_in(place, l + count, n + count);
		ft_write_in(place, l - count, n + count);
		ft_write_in(place, l + count, n - count);
		ft_write_in(place, l - count, n - count);
		ft_write_in(place, l - count, n);
		ft_write_in(place, l + count, n);
		ft_write_in(place, l, n - count);
		ft_write_in(place, l, n + count);
		count++;
	}
}

void	ft_eight_queens_recursive(int place_origin[8][8], int n)
{
	int place[9][8];
	int new[9][8];
	int	count;
	int	result;

	result = 0;
	count = -1;
	ft_array_copy(place_origin, place, 8);
	if (n == 7)
	{
		while (count++ < 7)
			ft_putchar(place[8][count] + 48);
		count = -1;
		ft_putchar('\n');
	}
	else
		while (count++ < 7)
			if (place[n + 1][count] == 0)
			{
				ft_array_copy(place, new, 8);
				ft_putchess(new, n + 1, count);
				new[8][n + 1] = count + 1;
				ft_eight_queens_recursive(new, n + 1);
			}
}

void	ft_eight_queens_puzzle_2(void)
{
	int	place[9][8];
	int new[9][8];
	int count;
	int result;
	int	count_two;

	result = 0;
	count = 8;
	while (count > 0)
	{
		count_two = 8;
		while (count_two > 0)
			place[count - 1][count_two--] = 0;
		count--;
	}
	while (count < 8)
	{
		ft_array_copy(place, new, 8);
		ft_putchess(new, 0, count);
		new[8][0] = count + 1;
		ft_eight_queens_recursive(new, 0);
		count++;
	}
}
