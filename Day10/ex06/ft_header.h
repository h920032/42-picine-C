/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:44:03 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 20:57:55 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <unistd.h>

void	ft_putchar_me(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_me(int nb)
{
	int	new_nb;

	if (nb == 0)
		ft_putchar_me(nb + 48);
	else if (nb > 0)
	{
		new_nb = nb / 10;
		if (new_nb != 0)
		{
			ft_putnbr_me(new_nb);
		}
		ft_putchar_me(nb % 10 + 48);
	}
	else
	{
		ft_putchar_me('-');
		new_nb = 0 - (nb / 10);
		if (new_nb != 0)
		{
			ft_putnbr_me(new_nb);
		}
		ft_putchar_me(0 - (nb % 10) + 48);
	}
}

void	ft_putstr_me(char *str)
{
	int		ptr_count;
	char	temp;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while (temp != '\0')
	{
		ft_putchar_me(temp);
		ptr_count++;
		temp = *(str + ptr_count);
	}
}

int		ft_atoi_me(char *string)
{
	int				result;
	unsigned int	digit;
	int				sign;

	result = 0;
	sign = 1;
	if (*string == '-')
		string += 1;
	else
	{
		sign = 0;
		if (*string == '+')
			string += 1;
	}
	while (1)
	{
		digit = *string - '0';
		if (digit > 9)
			break ;
		result = (10 * result) + digit;
		string++;
	}
	if (sign)
		return (-result);
	return (result);
}

#endif
