/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:04:42 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/21 20:12:28 by hsshih           ###   ########.fr       */
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
		if (*(str + count) != '*' && (count == 0 || *(str + count - 1) ==
		'*'))
			*(output + c) = temp + count;
		else if ((*(str + count) == '*' || *(str + count) == '\0') &&
				count != 0 && (*(str + count - 1) != '*'))
		{
			*(temp + count) = '\0';
			c++;
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
		if ((count == 0 || *(str + count) == '*') && (*(str + count
						+ 1) != '*' && *(str + count + 1) != '\0'))
			n++;
	}
	output = (char**)malloc(sizeof(char*) * (n + 1));
	if (n == 0)
		*output = 0;
	else
		ft_assign(output, temp, str, &n);
	return (output);
}

char	*match_first

int	match(char *s1, char *s2)
{
	char	**split;
	int		count;
	char	*ptr_1;
	char	*ptr_2;

	count = 0;
	if (s2 == 0 || s2 == 0)
		return (0);
	split = ft_split_whitespaces(s2);
	ptr_1 = s1;
	ptr_2 = split[count];
	while (*ptr_1 == '\0')
	{
		while (count == 0)
		{
			if (*ptr_1 != *ptr_2 && *ptr_2 != '\0')
				return (0);
			else if (*ptr_2 == '\0')
			{
				count++;
				ptr_2 = 
			}
			else
				ptr_2++;
		}
		ptr_1++;
	}
}
