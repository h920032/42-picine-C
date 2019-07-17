/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:19:57 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/15 17:29:10 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	count;
	int	nb;

	count = 0;
	nb = n;
	while (*(s1 + count) == *(s2 + count))
	{
		if (*(s1 + count) == '\0' || count >= nb - 1)
		{
			return (0);
		}
		count++;
	}
	return (*(s1 + count) - *(s2 + count));
}
