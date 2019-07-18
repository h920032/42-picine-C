/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:45:41 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/18 01:37:12 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_neg(int *var, char *str)
{
	int	count;

	count = -1;
	while (*(str + ++count) != '\0')
		if (*(str + count) == '-' && var != 0)
		{
			var[3] = 1;
			var[4] = count + 1;
			var = 0;
		}
		else if (*(str + count) == '+' && var != 0)
		{
			var[3] = 0;
			var[4] = count + 1;
			var = 0;
		}
		else if (*(str + count) >= 32 && *(str + count) <= 126
				&& var != 0)
		{
			var[3] = 0;
			var[4] = count;
			var = 0;
		}
	return (count);
}

int		ft_base_change(int b, char *base, char c)
{
	int		count;

	count = 0;
	while (count < b)
	{
		if (*(base + count) == c)
			return (count);
		count++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		b;
	int		var[5];

	b = ft_is_neg(0, base);
	var[0] = ft_is_neg(var, str) - 1;
	var[1] = 1;
	var[2] = 0;
	if (b == 0 || b == -1 || str == 0 || *str == '\0')
		return (0);
	else
	{
		while (var[0] >= var[4] &&
				ft_base_change(b, base, *(str + var[0])) != -1)
		{
			var[2] = var[2] + var[1] * ft_base_change(b, base, *(str + var[0]));
			var[1] = var[1] * b;
			var[0]--;
		}
		if (var[0] > var[4] && (ft_base_change(b, base, *(str + var[0])) == -1))
			return (0);
		if (var[3] == 1)
			var[2] = -var[2];
		return (var[2]);
	}
}

int		ft_putnbr_base(int nbr, char *base, char *output, int r)
{
	int	new_nb;
	int b;

	b = ft_is_neg(0, base);
	if (nbr == 0)
		*(output + r) = *(base + nbr);
	else if (nbr > 0)
	{
		new_nb = nbr / b;
		if (new_nb != 0)
			r = ft_putnbr_base(new_nb, base, output, r);
		*(output + r) = *(base + nbr % b);
	}
	else
	{
		*(output + r) = '-';
		new_nb = 0 - (nbr / b);
		if (new_nb != 0)
			r = ft_putnbr_base(new_nb, base, output, 1);
		*(output + r) = *(base - (nbr % b));
	}
	return (r + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		temp;
	char	*output;

	output = (char*)malloc(sizeof(*output) * 34);
	temp = ft_atoi_base(nbr, base_from);
	*(output + ft_putnbr_base(temp, base_to, output, 0)) = '\0';
	return (output);
}
