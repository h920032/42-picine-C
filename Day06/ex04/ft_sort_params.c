/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:29:07 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/17 02:01:13 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		ptr_count;
	char	temp;

	ptr_count = 0;
	temp = *(str + ptr_count);
	while (temp != '\0')
	{
		ft_putchar(temp);
		ptr_count++;
		temp = *(str + ptr_count);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (*(s1 + count) == *(s2 + count))
	{
		if (*(s1 + count) == '\0')
		{
			return (0);
		}
		count++;
	}
	return (*(s1 + count) - *(s2 + count));
}

int		main(int argc, char **argv)
{
	int		a;
	int		c;
	int		max_num;

	a = 1;
	while (a < argc)
	{
		max_num = 0;
		c = 1;
		while (c < argc)
		{
			if (argv[c] != 0 && max_num == 0)
				max_num = c;
			else if (argv[c] != 0 && max_num != 0
					&& ft_strcmp(argv[c], argv[max_num]) < 0)
				max_num = c;
			c++;
		}
		ft_putstr(argv[max_num]);
		argv[max_num] = 0;
		ft_putchar('\n');
		a++;
	}
	return (0);
}
