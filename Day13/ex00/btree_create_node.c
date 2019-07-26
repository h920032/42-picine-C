/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:50:15 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/26 01:58:44 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*output;

	output = (t_btree*)malloc(sizeof(*output));
	output->parent = NULL;
	output->right = NULL;
	output->left = NULL;
	output->data = item;
	return (output);
}
