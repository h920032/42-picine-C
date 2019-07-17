/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:44:26 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/15 19:34:30 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*origin;

	origin = str;
	while (*str != '\0')
	{
		if (*str <= 'Z' && *str >= 'A')
			*str = *str + 32;
		str++;
	}
	return (origin);
}

char	*ft_strcapitalize(char *str)
{
	int	count;

	ft_strlowcase(str);
	count = 0;
	while (*(str + count) != '\0')
	{
		if (*(str + count) <= 'z' && *(str + count) >= 'a')
		{
			if (count == 0)
			{
				*(str + count) = *(str + count) - 32;
			}
			else if (count != 0 && ((*(str + count - 1) < 'a'
					&& (*(str + count - 1) > 'Z' || *(str + count - 1) < 'A')
					&& (*(str + count - 1) > '9' || *(str + count - 1) < '0'))
					|| *(str + count - 1) >= 'z'))
			{
				*(str + count) = *(str + count) - 32;
			}
		}
		count++;
	}
	return (str);
}
