/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 00:11:21 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/19 00:12:02 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sastantua(int size);

int		ft_strlen(char *str)
{
	char	temp;
	int		ptr_count;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while ((temp != '\0' && temp <= '9' && temp >= '0') || temp == '\n' ||
			temp == '\t' || temp == '\v' || temp == ' ' || temp == '\f' ||
			temp == '\r' || temp == '-' || temp == '+')
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
		var[3] = 0;
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
	while (var[0] >= var[4] && *(str + var[0]) <= '9' && *(str + var[0]) >= '0')
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

int	main(int argc, char **argv)
{
	if (argc > 2)
		sastantua(ft_atoi(argv[1]));
	return (0);
}
