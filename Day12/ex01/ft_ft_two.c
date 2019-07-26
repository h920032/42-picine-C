/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:21:59 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 17:07:07 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_print_out(int c, char **argv)
{
	int	s;
	int	fd;

	s = 1;
	while (c)
	{
		if (argv[c + 1] == 0)
			return (1);
		fd = open(argv[c + 1], O_WRONLY | O_CREAT);
		close(fd);
		while (s < c)
		{
			if (argv[s][0] == '-' && argv[s][1] == '\0')
				ft_stdin(1);
			else
			{
				if (!ft_print_file(argv[s], 0))
					return (1);
			}
			s++;
		}
		s = c + 1;
		c = ft_is_write_file((argv + c + 1));
	}
	return (0);
}
