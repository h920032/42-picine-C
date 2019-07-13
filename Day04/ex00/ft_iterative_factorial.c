/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:21:12 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 14:06:52 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 1 || nb == 0)
	{
		return (1);
	}
	else if (nb > 1 && nb < 13)
	{
		while (nb)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
	else
	{
		return (0);
	}
}
