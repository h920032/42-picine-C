/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:41:00 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 21:50:37 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb, int time)
{
	int		new_nb;
	char	*hexadecimals;

	hexadecimals = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putchar(*(hexadecimals + nb));
	}
	else if (nb < 0)
		ft_putnbr(256 + nb, 0);
	else if (nb > 0)
	{
		new_nb = nb / 16;
		if (time == 0)
		{
			time++;
			ft_putnbr(new_nb, time);
		}
		ft_putchar(*(hexadecimals + nb % 16));
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str <= 127 && *str >= -128 && *str != '\0')
	{
		if (*str < 127 && *str >= 32)
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putnbr(*str, 0);
		}
		str++;
	}
}
