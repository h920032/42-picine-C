/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:29:28 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/25 00:00:42 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_stdin(void)
{
	char	buf;

	while (read(0, &buf, 1))
	{
		write(1, &buf, 1);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	buf[BUF_SIZE + 1];

	if (argc - 1 < 1 || argv[1][0] == '-')
		ft_stdin();
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd >= 0)
			while (read(fd, &buf, 1) != 0)
				write(1, &buf, 1);
		else
		{
			ft_putstr("ft_cat");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
			return (1);
		}
		close(fd);
		i++;
	}
	return (0);
}
