/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:16:59 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 09:18:29 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	if(nb == 0)
	{
		ft_putchar(nb + 48);
	}
	else if(nb > 0)
	{
		int		new_nb;
		new_nb = nb / 10;
		if(new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(nb % 10 + 48);
	}
	else
	{
		int		new_nb;
		ft_putchar('-');
		new_nb = (0 - nb) / 10;
		if(new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar((0 - nb) % 10 + 48);
	}
}
