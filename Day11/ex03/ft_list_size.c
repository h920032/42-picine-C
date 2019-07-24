/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:40:29 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 21:45:00 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 1;
	if (begin_list == NULL)
		return (0);
	while (begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
