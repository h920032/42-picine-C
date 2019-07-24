/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:32:32 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/24 11:16:39 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*temp;
	t_list	*temp_two;
	t_list	*temp_three;
	t_list	*store;
	t_list	swap;

	temp = begin_list;
	if (temp == NULL || temp->next == NULL)
		return ;
	store = begin_list->next;
	temp_two = temp->next;
	temp_three = temp_two->next;
	temp->next = NULL;
	while (temp_three != NULL)
	{
		temp_two->next = temp;
		temp = temp_two;
		temp_two = temp_three;
		temp_three = temp_three->next;
	}
	temp_two->next = temp;
	store->next = temp_two;
	swap = *temp_two;
	*temp_two = *begin_list;
	*begin_list = swap;
}
