/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:33:35 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/17 23:22:09 by hugoshih         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	len;

	len = 0;
	while (len <= ft_strlen(src))
	{
		*(dest + len) = *(src + len);
		len++;
	}
	return (dest);
}

void	ft_assign(char **output, char *temp, char *str, int *n)
{
	int	count;
	int	c;

	count = -1;
	c = 0;
	while (*(str + ++count) != '\0' && c < *n)
		if (*(str + count) != ' ' && *(str + count) != '\n' && *(str +
		count) != '\t' && (count == 0 || *(str + count - 1) ==
		'\n' || *(str + count - 1) == '\t' || *(str + count - 1) == ' '))
			*(output + c) = temp + count;
		else if ((*(str + count) == ' ' || *(str + count) == '\t' ||
			*(str + count) == '\n' || *(str + count) == '\0')
				&& count != 0 &&
			(*(str + count - 1) != ' ' && *(str + count - 1) != '\t' &&
			*(str + count - 1) != '\n'))
		{
			*(temp + count) = '\0';
			c = c + 1;
		}
	if (*(str + count) == '\0')
	{
		*(temp + count) = '\0';
		c++;
	}
	*(output + c) = 0;
}

char	**ft_split_whitespaces(char *str)
{
	int		count;
	int		n;
	char	*temp;
	char	**output;

	if (str == 0)
		return (0);
	temp = (char*)malloc(sizeof(*temp) * (ft_strlen(str) + 1));
	ft_strcpy(temp, str);
	count = -1;
	n = 0;
	while (*(str + ++count) != '\0')
	{
		if ((count == 0 || *(str + count) == ' ' || *(str + count) == '\t' ||
			*(str + count) == '\n') && (*(str + count + 1) != ' ' &&
			*(str + count + 1) != '\t' && *(str + count + 1) != '\n' &&
			*(str + count + 1) != '\0'))
			n++;
	}
	output = (char**)malloc(sizeof(char*) * (n + 1));
	if (n == 0)
		*output = 0;
	else
		ft_assign(output, temp, str, &n);
	return (output);
}
