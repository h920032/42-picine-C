/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:12:47 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 16:27:42 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	count;
	
	if (nb == 2)
	{
		return(1);
	}
	else if (nb <= 1)
	{
		return (0);
	}
	count = nb / 2;
	while (count > 1)
	{
		if (nb % count == 0)
		{
			return (0);
		}
		count--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
	{
		return nb;
	}
	else if (nb % 2 == 0 || nb == 1)
	{
		return (ft_find_next_prime(nb + 1));
	}
	else
	{
		return (ft_find_next_prime(nb + 2));
	}
}
