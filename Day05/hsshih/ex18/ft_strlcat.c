/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:53:12 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/15 21:53:55 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char	*ptr;
	char	*str;
	int		nb;
	int		dlen;

	ptr = dest;
	str = src;
	nb = size;
	if (ptr == 0 || str == 0)
		return (0);
	while (*ptr != '\0' && nb-- != 0)
		ptr++;
	dlen = ptr - dest;
	nb = size - dlen;
	if (nb == 0)
		return (dlen + ft_strlen(src));
	while (*str != '\0')
	{
		if (nb-- > 1)
			*ptr++ = *str;
		str++;
	}
	*ptr = '\0';
	return (dlen + (str - src));
}
