/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:12:31 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/10 17:36:44 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int 	i;
	i = 0;
	while(i <= 7)
	{
		int		j;
		j = i + 1;
		while(j <= 8)
		{
			int		k;
			k = j + 1;
			while(k <= 9)
			{
				ft_putchar(i + 48);
				ft_putchar(j + 48);
				ft_putchar(k + 48);
				if(i != 7 || j != 8 || k != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
