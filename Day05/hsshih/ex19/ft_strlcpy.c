/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:54:35 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 11:17:04 by hsshih           ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		nb;
	char	*ptr;

	ptr = src;
	if (dest == 0 || src == 0)
		return (0);
	nb = size;
	if (nb > 0)
	{
		while (*src != '\0' && nb > 1)
		{
			*dest = *ptr;
			dest++;
			ptr++;
			nb--;
		}
		*dest = '\0';
	}
	return (ft_strlen(src));
}
