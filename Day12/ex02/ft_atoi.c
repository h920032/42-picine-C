/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:39:57 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 19:40:37 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
