/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:17:28 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 15:23:09 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (result);
	}
	else if (power < 2000)
	{
		while (power)
		{
			result *= nb;
			power--;
		}
		return (result);
	}
	else
	{
		return (-1);
	}
}
