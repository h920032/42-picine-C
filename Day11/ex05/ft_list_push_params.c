/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:48:29 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/23 21:58:14 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*temp;
	t_list	*new;
	int		count;

	if (ac <= 0 || av == NULL)
		return (NULL);
	count = 0;
	temp = NULL;
	while (count < ac)
	{
		new = ft_create_elem(av[count]);
		new->next = temp;
		temp = new;
		count++;
	}
	return (temp);
}
