/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:19:25 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/24 14:33:11 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*insert;
	t_list	*temp;

	insert = ft_create_elem(data);
	temp = *begin_list;
	if (temp == NULL || cmp(temp->data, insert->data) > 0)
	{
		*begin_list = insert;
		insert->next = temp;
		return ;
	}
	while (temp->next != NULL)
	{
		if (cmp(temp->next->data, insert->data) > 0)
		{
			insert->next = temp->next;
			temp->next = insert;
			return ;
		}
		temp = temp->next;
	}
	temp->next = insert;
}
