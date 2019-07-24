/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:19:00 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/24 10:31:05 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*temp;
	t_list	*c;
	t_list	*r;
	t_list	*max;

	r = *begin_list;
	if (*begin_list == NULL)
		return ;
	while (r != NULL)
	{
		max = NULL;
		c = r;
		while (c != NULL)
		{
			if (max == NULL)
				max = c;
			else if (cmp(max->data, c->data) > 0)
				max = c;
			c = c->next;
		}
		temp = r->data;
		r->data = max->data;
		max->data = temp;
		r = r->next;
	}
}
