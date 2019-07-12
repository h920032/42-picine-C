/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:16:59 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 16:16:51 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	new_nb;

	if (nb == 0)
	{
		ft_putchar(nb + 48);
	}
	else if (nb > 0)
	{
		new_nb = nb / 10;
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(nb % 10 + 48);
	}
	else
	{
		ft_putchar('-');
		new_nb = 0 - (nb / 10);
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(0 - (nb % 10) + 48);
	}
}
