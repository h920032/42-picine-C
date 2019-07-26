/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:32:09 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 22:37:52 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_print_list(t_list *b, int offset)
{
	int	count;

	count = 0;
	if (b == NULL)
		return ;
	if (offset == 0)
	{
		while (b != NULL)
		{
			write(1, &(b->data), 1);
			b = b->next;
		}
	}
	else
	{
		while (count < offset)
		{
			b = b->next;
			count++;
		}
		ft_print_list(b, 0);
	}
}

void	ft_list_push_back(t_list **begin_list, char data)
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

void	ft_short(int *nl, t_list *data[10], char *buf, int *count)
{
	int	c;

	if (*nl)
	{
		c = -1;
		ft_list_clear(&(data[0]));
		while (++c < 9)
			data[c] = data[c + 1];
		data[9] = NULL;
		*nl = 0;
	}
	ft_list_push_back(&data[*count], *buf);
	if (*buf == '\n')
	{
		if (*count < 9)
			(*count)++;
		else
			*nl = 1;
	}
}

void	ft_stdin(void)
{
	int		count;
	t_list	*data[10];
	char	buf;
	int		c;
	int		nl;

	c = -1;
	nl = 0;
	while (++c < 10)
		data[c] = NULL;
	count = 0;
	while (read(0, &buf, 1))
	{
		ft_short(&nl, data, &buf, &count);
	}
	c = -1;
	while (++c < 10)
		ft_print_list(data[c], 0);
}
