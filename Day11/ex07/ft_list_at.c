/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:12:28 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 22:25:48 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned	count;

	count = 0;
	if (begin_list == NULL)
		return (NULL);
	while (count < nbr)
	{
		if (begin_list->next == NULL)
			return (NULL);
		else
			begin_list = begin_list->next;
		count++;
	}
	return (begin_list);
}
