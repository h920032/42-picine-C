/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:29:25 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/12 11:08:37 by hsshih           ###   ########.fr       */
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

void	ft_is_neg(int *var, char *str)
{
	if (*(str) == '-')
	{
		var[3] = 1;
		var[4] = 1;
	}
	else
	{
		var[4] = 0;
	}
}

int		ft_atoi(char *str)
{
	char	temp;
	int		var[5];

	ft_is_neg(var, str);
	var[0] = ft_strlen(str);
	var[1] = 1;
	var[2] = 0;
	var[0]--;
	while (var[0] >= var[4])
	{
		temp = *(str + var[0]);
		var[2] = var[2] + var[1] * (temp - 48);
		var[1] = var[1] * 10;
		var[0]--;
	}
	if (var[3] == 1)
	{
		var[2] = 0 - var[2];
	}
	return (var[2]);
}
