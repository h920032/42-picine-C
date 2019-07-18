/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:17:23 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/17 20:41:20 by hsshih           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\n';
	ptr++;
	*ptr = *src;
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		size;
	int		count;
	char	*output;

	size = 0;
	count = 1;
	if (argc == 0 || *argv == 0)
		return (0);
	while (count < argc)
	{
		if (*(argv + count) == 0)
			return (0);
		size += ft_strlen(*(argv + count));
		count++;
	}
	output = (char*)malloc(sizeof(*output) * (size + argc - 1));
	count = 1;
	while (count < argc)
	{
		ft_strcat(output, *(argv + count));
		count++;
	}
	*(output + size + argc - 2) = '\0';
	return (output);
}
