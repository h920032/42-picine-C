/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:58:26 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/11 21:26:29 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char	*str)
{
	char	temp;
	char	temp2;
	int	ptr_count;
	int	count;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while (temp != '\0')
	{
		ptr_count++;
		temp = *(str + ptr_count);
	}
	count = 0;
	while (count < (ptr_count / 2))
	{
		temp2 = *(str + count);
		*(str + count) = *(str + ptr_count - 1 - count);
		*(str + ptr_count - 1 - count) = temp2;
		count++;
	}
	return (str);
}
