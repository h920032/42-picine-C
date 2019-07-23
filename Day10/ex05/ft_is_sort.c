/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:54:23 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 16:08:50 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	count;

	if (length < 0 || tab == 0 || f == 0)
		return (0);
	if (length < 2)
		return (1);
	count = 1;
	while (count < length)
	{
		if (f(tab[count - 1], tab[count]) > 0)
			return (0);
		count++;
	}
	return (1);
}
