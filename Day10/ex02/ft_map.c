/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:17:38 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 15:23:19 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	*output;
	int	count;

	count = 0;
	if (length <= 0 || tab == 0 || f == 0)
		return (0);
	output = (int*)malloc(sizeof(*output) * length);
	while (count < length)
	{
		output[count] = f(tab[count]);
		count++;
	}
	return (output);
}
