/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:17:02 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 21:27:59 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = *begin_list;
	if (temp == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ft_create_elem(data);
}
