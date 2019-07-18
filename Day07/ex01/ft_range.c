/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:43:26 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/17 17:01:40 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*output;

	if (min >= max)
		return (0);
	output = (int*)malloc(sizeof(*output) * (max - min));
	while (max > min)
	{
		*(output + max - min - 1) = max - 1;
		max--;
	}
	return (output);
}
