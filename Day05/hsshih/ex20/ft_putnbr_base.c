/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:09:45 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 20:35:24 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_base_change(int base, char c)
{
	int		count;
	char	*octal;
	char	*hexadecimal;
	char	*decimal;
	char	*binary;

	octal = "poneyvif";
	hexadecimal = "0123456789ABCDEF";
	decimal = "0123456789";
	binary = "01";
	count = 0;
	while (count < base)
	{
		if (base == 2 && *(binary + count) == c)
			return (count);
		else if (base == 8 && *(octal + count) == c)
			return (count);
		else if (base == 10 && *(decimal + count) == c)
			return (count);
		else if (base == 16 && *(hexadecimal + count) == c)
			return (count);
		count++;
	}
	return (-1);
}

void	ft_temp(int *b, int *data, char *base)
{
	if (*b != 0 && *b != -1)
	{
		if (*(data + ft_base_change(*b, *base)) == 0)
			*(data + ft_base_change(*b, *base)) = 1;
		else
			*b = -1;
	}
}

int		ft_base(char *base)
{
	int		b;
	int		data[16];

	b = -1;
	while (b++ < 16)
		data[b] = 0;
	b = 0;
	if (base == 0)
		return (0);
	while (*base != '\0' && b != -1)
	{
		if ((b == 0 || b == 2) && ft_base_change(2, *base) != -1)
			b = 2;
		else if ((b != 8 && b != 16) && ft_base_change(10, *base) != -1)
			b = 10;
		else if (b != 8 && ft_base_change(16, *base) != -1)
			b = 16;
		else if ((b == 0 || b == 8) && ft_base_change(8, *base) != -1)
			b = 8;
		else
			b = -1;
		ft_temp(&b, data, base);
		base++;
	}
	return (b);
}

void	ft_base_char(int nb, int b)
{
	char	*octal;
	char	*hexadecimal;
	char	*decimal;
	char	*binary;

	octal = "poneyvif";
	hexadecimal = "0123456789ABCDEF";
	decimal = "0123456789";
	binary = "01";
	if (b == 2)
		ft_putchar(*(binary + nb));
	else if (b == 8)
		ft_putchar(*(octal + nb));
	else if (b == 10)
		ft_putchar(*(decimal + nb));
	else if (b == 16)
		ft_putchar(*(hexadecimal + nb));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	new_nb;
	int b;

	b = ft_base(base);
	if (b == 0)
		return ;
	if (nbr == 0)
	{
		ft_base_char(nbr, b);
	}
	else if (nbr > 0)
	{
		new_nb = nbr / b;
		if (new_nb != 0)
			ft_putnbr_base(new_nb, base);
		ft_base_char(nbr % b, b);
	}
	else
	{
		ft_putchar('-');
		new_nb = 0 - (nbr / b);
		if (new_nb != 0)
			ft_putnbr_base(new_nb, base);
		ft_base_char(0 - (nbr % b), b);
	}
}
