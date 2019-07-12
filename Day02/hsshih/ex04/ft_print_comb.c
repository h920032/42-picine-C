/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:12:31 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 16:15:43 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	var[3];

	var[0] = 0;
	while (var[0] <= 7)
	{
		var[1] = var[0] + 1;
		while (var[1] <= 8)
		{
			var[2] = var[1] + 1;
			while (var[2] <= 9)
			{
				ft_putchar(var[0] + 48);
				ft_putchar(var[1] + 48);
				ft_putchar(var[2] + 48);
				if (var[0] != 7 || var[1] != 8 || var[2] != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				var[2]++;
			}
			var[1]++;
		}
		var[0]++;
	}
}
