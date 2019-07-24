/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:59:01 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 22:10:42 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*temp;

	temp = *begin_list;
	if (*begin_list == NULL || begin_list == NULL)
		return ;
	else
	{
		ft_list_clear(&(temp->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}
