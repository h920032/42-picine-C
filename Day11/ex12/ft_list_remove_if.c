/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 00:55:14 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/24 01:27:29 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*del;
	t_list	tmp;

	if (begin_list == NULL || data_ref == NULL || cmp == NULL)
		return ;
	temp = &tmp;
	temp->next = *begin_list;
	while (temp->next != NULL)
	{
		if ((*cmp)(temp->next->data, data_ref) == 0)
		{
			del = temp->next;
			temp->next = temp->next->next;
			free(del);
		}
		else
		{
			temp = temp->next;
		}
	}
	*begin_list = tmp.next;
}
