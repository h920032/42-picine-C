/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:34:41 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/24 16:01:03 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_short(t_list **one_f, t_list **two_f, t_list **now_f, int (*cmp)())
{
	t_list	*one;
	t_list	*two;
	t_list	*now;

	one = *one_f;
	two = *two_f;
	now = *now_f;
	while (one != NULL && two != NULL)
	{
		if (cmp(one->data, two->data) < 0)
		{
			now->next = one;
			one = one->next;
		}
		else
		{
			now->next = two;
			two = two->next;
		}
		now = now->next;
	}
	if (one == NULL)
		now->next = two;
	else
		now->next = one;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*one;
	t_list	*two;
	t_list	*now;

	one = *begin_list1;
	two = begin_list2;
	if (one == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	else if (two == NULL)
		return ;
	if (cmp(one->data, two->data) < 0)
	{
		now = one;
		one = one->next;
	}
	else
	{
		now = two;
		two = two->next;
	}
	*begin_list1 = now;
	ft_short(&one, &two, &now, cmp);
}
