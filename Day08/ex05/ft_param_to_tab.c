/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:32:56 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/18 21:03:47 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	char	temp;
	int		ptr_count;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while (temp != '\0')
	{
		ptr_count++;
		temp = *(str + ptr_count);
	}
	return (ptr_count);
}

char				*ft_strdup(char *src)
{
	int		len;
	char	*cpy;

	if (src == 0)
		return (0);
	len = ft_strlen(src);
	cpy = (char*)malloc(sizeof(*cpy) * (len + 1));
	while (len > 0)
	{
		*(cpy + len - 1) = *(src + len - 1);
		len--;
	}
	*(cpy + ft_strlen(src)) = '\0';
	return (cpy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			c;
	t_stock_par	*output;

	c = 0;
	output = (t_stock_par*)malloc(sizeof(*output) * (ac + 1));
	while (c < ac)
	{
		(output + c)->size_param = ft_strlen(*(av + c));
		(output + c)->str = *(av + c);
		(output + c)->copy = ft_strdup(*(av + c));
		(output + c)->tab = ft_split_whitespaces(*(av + c));
		c++;
	}
	(output + ac)->str = 0;
	return (output);
}
