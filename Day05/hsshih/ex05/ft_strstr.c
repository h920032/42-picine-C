/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:22:45 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 11:25:35 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;

	if (*to_find)
	{
		while (*str)
		{
			count = 0;
			while (*(to_find + count) == *(str + count) && *(str + count))
			{
				if (!*(to_find + count + 1))
					return (str);
				count++;
			}
			str++;
		}
		return (0);
	}
	else
		return (str);
}
