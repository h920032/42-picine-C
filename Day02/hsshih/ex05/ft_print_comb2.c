/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:38:53 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/10 17:56:58 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int 	i;
	i = 0;
	while(i <= 98)
	{
		int		j;
		j = i + 1;
		while(j <= 99)
		{
			int		ten_dig_1;
			ten_dig_1 = i / 10;
			int     uni_dig_1;
			uni_dig_1 = i % 10;
			int     ten_dig_2;
            ten_dig_2 = j / 10;
            int     uni_dig_2;
            uni_dig_2 = j % 10;
			ft_putchar(ten_dig_1 + 48);
			ft_putchar(uni_dig_1 + 48);
			ft_putchar(' ');
			ft_putchar(ten_dig_1 + 48);
			ft_putchar(uni_dig_2 + 48);
			if(i != 98 || j != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}
