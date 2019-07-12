/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:38:53 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 16:30:35 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_divide(int *var)
{
	var[2] = var[0] / 10;
	var[3] = var[0] % 10;
	var[4] = var[1] / 10;
	var[5] = var[1] % 10;
}

void	ft_print_comb2(void)
{
	int var[6];

	var[0] = 0;
	while (var[0] <= 98)
	{
		var[1] = var[0] + 1;
		while (var[1] <= 99)
		{
			ft_divide(var);
			ft_putchar(var[2] + 48);
			ft_putchar(var[3] + 48);
			ft_putchar(' ');
			ft_putchar(var[4] + 48);
			ft_putchar(var[5] + 48);
			if (var[0] != 98 || var[1] != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			var[1]++;
		}
		var[0]++;
	}
}
