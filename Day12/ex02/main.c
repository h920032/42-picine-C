/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:32:56 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 22:26:38 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_print_error_two(char *str)
{
	ft_putstr("tail: illegal offset -- ");
	ft_putstr(str);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc - 1 < 1 || (argc == 2 && argv[1][0] == '-' && argv[1][1] == '-'
				&& argv[1][2] == '\0'))
		ft_stdin();
	else if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'c' && argv[1][2] == '\0')
		{
			if (argc > 2 && ft_is_num(argv[2]))
				ft_print(argv, argc);
			else if (argc > 2)
				ft_print_error_two(argv[2]);
			else
				ft_print_error();
		}
		else
		{
			ft_putstr("tail: illegal option --  ");
			ft_putchar(argv[1][1]);
			ft_putstr("\nusage: tail [-F | -f | -r] [-q] [-b # | -c # | ");
			ft_putstr("-n #] [file ...]\n");
		}
	}
	else
		ft_print_filein(argv, argc);
	return (0);
}
