/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:12:47 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 16:27:42 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_array_copy(int origin[8][8], int copy[8][8], int n)
{
	int count_one;
	int	count_two;

	count_one = 0;
	while (count_one < n)
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

void	ft_write_in(int place[8][8], int l, int n)
{
	if (l <= 7 && n <= 7 && l >= 0 && n >= 0)
	{
		place[l][n] = 1;
	}
}

void	ft_putchess(int place[8][8], int l, int n)
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

int	ft_eight_queens_recursive(int place_origin[8][8], int n)
{
	int place[8][8];
	int new[8][8];
	int	count;
	int	result;
		
	result = 0;
	count = 0;
	ft_array_copy(place_origin, place, 8);
	if (n == 7)
	{
		printf("%d", 1);
		return (1);
	}
	else
	{
		while(count < 8)
		{
			if (place[n + 1][count] == 0)
			{
				ft_array_copy(place, new, 8);
				ft_putchess(new, n + 1, count);
				result = result + ft_eight_queens_recursive(new, n + 1);
				printf("(%d,%d)", n + 1, count);		
			}
			count++;
		}
	}
	return (result);
}

int	ft_eight_queens_puzzle(void)
{
	int	place[8][8];
	int count;
	int result;
	int	count_two;
	
	result = 0;
	count = 8;
	count_two = 8;
	while (count > 0)
	{
		while (count_two > 0)
		{
			place[count - 1][count_two - 1] = 0;
			count_two--;
		}
		count--;
	}
	while (count < 8)
	{
		ft_putchess(place, 0, count);
		result = result + ft_eight_queens_recursive(place, 0);
		count++;
	}
	return (result);
}

int main()
{
	printf("%d", ft_eight_queens_puzzle());
	return (0);
}
