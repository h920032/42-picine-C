/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:12:39 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/21 21:36:37 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_first_sub(char *ptr[2])
{
	while (*ptr[1] != '*' && *ptr[1] != '\0' && *ptr[0] != '\0')
	{
		if (*ptr[1] != *ptr[0])
			return (0);
		ptr[1]++;
		ptr[0]++;
	}
	if (*ptr[1] != '*' && *ptr[1] != '\0' && *ptr[0] == '\0')
		return (0);
	ptr[1]++;
	return (1);
}

int		ft_sub(char *ptr[2])
{
	while (*ptr[1] != '*' && *ptr[1] != '\0' && *ptr[0] != '\0')
	{
		while (*ptr[1] != *ptr[0])
		{
			ptr[0]++;
			if (ptr[0] == '\0')
				return (0);
		}
		while (*ptr[1] == *ptr[0])
		{
			ptr[0]++;
			ptr[1]++;
		}
	}
	if (*ptr[1] != '*' && *ptr[1] != '\0' && *ptr[0] == '\0')
		return (0);
	ptr[1]++;
	return (1);
}

int		match(char *s1, char *s2)
{
	char	*ptr[2];

	ptr[0] = s1;
	ptr[1] = s2;
	if (ft_first_sub(ptr))
	{
		if (ft_sub(ptr))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int main()
{
	char *one = "test.c";
	char *two = "test*.c";
	char *ptr[2];
	ptr[0] = one;
	ptr[1] = two;

	printf("%d", ft_first_sub(ptr));
	return (0);

}
