/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:26:48 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/24 00:32:45 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*temp_two;
	t_list	*temp_three;

	temp = *begin_list;
	if (temp == NULL || temp->next == NULL)
		return ;
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
	*begin_list = temp_two;
}
