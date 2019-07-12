/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:20:42 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 17:13:31 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_init(int n, int *var, int *num, int *max)
{
	var[0] = n;
	while (var[0] > 0)
	{
		num[n - var[0]] = n - var[0];
		max[n - var[0]] = 10 - var[0];
		var[0]--;
	}
	var[1] = 0;
	while (var[1] < n)
	{
		ft_putchar(var[1] + 48);
		var[1]++;
	}
}

void	ft_loop(int n, int *var, int *num, int *max)
{
	while (var[3])
	{
		if (num[var[4] - 1] < max[var[4] - 1])
		{
			num[var[4] - 1]++;
			if (var[4] < n)
			{
				var[5] = var[4] + 1;
				while (var[5] <= n)
				{
					if (num[var[5] - 2] + 1 < max[var[5] - 1])
					{
						num[var[5] - 1] = num[var[5] - 2] + 1;
					}
					var[5]++;
				}
			}
			var[3] = 0;
			var[6] = 0;
			while (var[6] < n)
			{
				ft_putchar(num[var[6]] + 48);
				var[6]++;
			}
		}
		var[4]--;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	max[10];
	int	var[8];

	ft_init(n, var, num, max);
	ft_putchar(',');
	ft_putchar(' ');
	var[2] = 1;
	while (var[2])
	{
		var[3] = 1;
		var[4] = n;
		ft_loop(n, var, num, max);
		var[7] = 0;
		while (var[7] < n)
		{
			if (num[var[7]] != max[var[7]])
			{
				var[2] = 1;
				ft_putchar(',');
				ft_putchar(' ');
				break ;
			}
			else
			{
				var[2] = 0;
			}
			var[7]++;
		}
	}
}
