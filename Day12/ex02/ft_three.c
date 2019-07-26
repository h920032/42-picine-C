/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:39:55 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 22:41:29 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_print_file(int is_only, char *str, int index)
{
	int		var[3];

	var[1] = is_only;
	var[2] = index;
	var[0] = open(str, O_RDONLY);
	if (var[0] >= 0)
		ft_output_file(var, str);
	else
	{
		ft_putstr("tail: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	close(var[0]);
}

void	ft_print_size_stdin(int offset)
{
	int		c;
	t_list	*b;
	char	buf;

	c = 0;
	b = NULL;
	while (read(0, &buf, 1) != 0)
	{
		ft_list_push_back(&b, buf);
		c++;
	}
	ft_print_list(b, c - offset);
}

void	ft_print_filein(char **argv, int argc)
{
	int	c;

	if (argc - 1 > 0)
	{
		if (argc - 1 == 1)
			ft_print_file(1, argv[1], 3);
		else
		{
			c = 0;
			while (++c < argc)
				ft_print_file(0, argv[c], c);
		}
	}
	else
		ft_stdin();
}

void	ft_print(char **argv, int argc)
{
	int	offset;
	int	c;

	offset = ft_atoi_me(argv[2]);
	if (offset < 0)
		offset = -offset;
	if (argc - 1 > 2)
	{
		if (argc - 1 == 3)
			ft_print_size(1, offset, argv[3], 3);
		else
		{
			c = 2;
			while (++c < argc)
				ft_print_size(0, offset, argv[c], c);
		}
	}
	else
		ft_print_size_stdin(offset);
}

void	ft_print_error(void)
{
	ft_putstr("tail: option requires an argument -- c\n");
	ft_putstr("usage: tail [-F | -f | -r] [-q] [-b # | -c ");
	ft_putstr("# | -n #] [file ...]\n");
}
