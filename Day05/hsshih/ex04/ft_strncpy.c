/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:49:01 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/15 15:21:57 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	count;
	int nb;

	count = 0;
	nb = n;
	while (count < nb)
	{
		if (count >= ft_strlen(src))
			*(dest + count) = '\0';
		else
			*(dest + count) = *(src + count);
		count++;
	}
	return (dest);
}
