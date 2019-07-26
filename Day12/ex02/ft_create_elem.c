/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:28:37 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 22:29:21 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

t_list	*ft_create_elem(char data)
{
	t_list	*output;

	output = (t_list*)malloc(sizeof(*output) * 1);
	output->next = NULL;
	output->data = data;
	return (output);
}
