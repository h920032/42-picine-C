/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:15:22 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 20:08:04 by hsshih           ###   ########.fr       */
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

int		ft_base_change(int b, char *base, char c)
{
	int		count;

	count = 0;
	while (count < b)
	{
		if (*(base + count) == c)
			return (count);
		count++;
	}
	return (-1);
}

int		ft_base(char *str)
{
	int		ptr_count;
	int		count;

	ptr_count = ft_strlen(str);
	while (*str != '\0')
	{
		count = 1;
		if (*str < 32 || *str > 126 || *str == '-' || *str == '+')
			return (-1);
		else
			while (*(str + count) != '\0')
			{
				if (*str == *(str + count))
					return (-1);
				count++;
			}
		str++;
	}
	return (ptr_count);
}

void	ft_is_neg(int *var, char *str)
{
	int	count;

	count = 0;
	while (*(str + count) != '\0')
	{
		if (*(str + count) == '-')
		{
			var[3] = 1;
			var[4] = count + 1;
			break ;
		}
		else if (*(str + count) == '+')
		{
			var[3] = 0;
			var[4] = count + 1;
			break ;
		}
		else if (*(str + count) >= 32 && *(str + count) <= 126)
		{
			var[3] = 0;
			var[4] = count;
			break ;
		}
		count++;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int		b;
	int		var[5];

	b = ft_base(base);
	ft_is_neg(var, str);
	var[0] = ft_strlen(str) - 1;
	var[1] = 1;
	var[2] = 0;
	if (b == 0 || b == -1 || str == 0 || *str == '\0')
		return (0);
	else
	{
		while (var[0] >= var[4] &&
				ft_base_change(b, base, *(str + var[0])) != -1)
		{
			var[2] = var[2] + var[1] * ft_base_change(b, base, *(str + var[0]));
			var[1] = var[1] * b;
			var[0]--;
		}
		if (var[0] > var[4] && (ft_base_change(b, base, *(str + var[0])) == -1))
			return (0);
		if (var[3] == 1)
			var[2] = -var[2];
		return (var[2]);
	}
}
