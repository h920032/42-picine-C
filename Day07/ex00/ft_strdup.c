/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:35:24 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/17 16:13:06 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
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

char	*ft_strdup(char *src)
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
