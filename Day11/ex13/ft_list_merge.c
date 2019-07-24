/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 01:28:35 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/24 01:42:30 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*one;

	if (begin_list2 == NULL)
		return ;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	one = *begin_list1;
	while (one->next != NULL)
		one = one->next;
	one->next = begin_list2;
}
