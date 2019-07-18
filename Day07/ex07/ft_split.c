/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 01:38:52 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/18 02:15:32 by hugoshih         ###   ########.fr       */
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

int		ft_check(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

void	ft_assign(char **output, char **ar, int *n)
{
	int	count;
	int	c;

	count = -1;
	c = 0;
	while (*(ar[0] + ++count) != '\0' && c < *n)
		if (!ft_check(*(ar[0] + count), ar[1]) && (count == 0 ||
					ft_check(*(ar[0] + count - 1), ar[1])))
			*(output + c) = ar[2] + count;
		else if ((ft_check(*(ar[0] + count), ar[1]) || *(ar[0] + count) == '\0')
				&& count != 0 && (!ft_check(*(ar[0] + count - 1), ar[1])))
		{
			*(ar[2] + count) = '\0';
			c = c + 1;
		}
	if (*(ar[0] + count) == '\0')
	{
		*(ar[2] + count) = '\0';
		c++;
	}
	*(output + c) = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	int		n;
	char	**output;
	char	*ar[3];

	ar[0] = str;
	ar[1] = charset;
	if (str == 0)
		return (0);
	ar[2] = (char*)malloc(sizeof(*ar[2]) * (ft_strlen(str) + 1));
	ft_strcpy(ar[2], str);
	count = -1;
	n = 0;
	while (*(str + ++count) != '\0')
		if ((count == 0 || ft_check(*(str + count), charset)) &&
	(!ft_check(*(str + count + 1), charset) && *(str + count + 1) != '\0'))
			n++;
	output = (char**)malloc(sizeof(char*) * (n + 1));
	if (n == 0)
		*output = 0;
	else
		ft_assign(output, ar, &n);
	return (output);
}
