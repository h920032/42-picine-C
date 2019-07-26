/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:38:02 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 22:39:48 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_filein(int fd)
{
	int		count;
	t_list	*data[10];
	char	buf;
	int		c;
	int		nl;

	c = -1;
	nl = 0;
	while (++c < 10)
		data[c] = NULL;
	count = 0;
	while (read(fd, &buf, 1))
	{
		ft_short(&nl, data, &buf, &count);
	}
	c = -1;
	while (++c < 10)
		ft_print_list(data[c], 0);
}

int		ft_is_num(char *str)
{
	if (*str != '+' && *str != '-' && !(*str >= '0' && *str <= '9'))
		return (0);
	str++;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	ft_output(int var[4], char *str)
{
	char	buf;
	int		c;
	t_list	*b;

	c = 0;
	b = NULL;
	if (var[3] != 3)
		ft_putchar('\n');
	if (!var[1])
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}
	while (read(var[0], &buf, 1) != 0)
	{
		ft_list_push_back(&b, buf);
		c++;
	}
	ft_print_list(b, c - var[2]);
}

void	ft_print_size(int is_only, int offset, char *str, int index)
{
	int		var[4];

	var[1] = is_only;
	var[2] = offset;
	var[3] = index;
	var[0] = open(str, O_RDONLY);
	if (var[0] >= 0)
		ft_output(var, str);
	else
	{
		ft_putstr("tail: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	close(var[0]);
}

void	ft_output_file(int var[3], char *str)
{
	int		c;
	t_list	*b;

	c = 0;
	b = NULL;
	if (var[2] != 1)
		ft_putchar('\n');
	if (!var[1])
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}
	ft_filein(var[0]);
}
