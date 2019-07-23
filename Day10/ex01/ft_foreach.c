/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:08:10 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 15:16:17 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	count;

	count = 0;
	if (length <= 0)
		return ;
	while (count < length)
	{
		f(tab[count]);
		count++;
	}
}
