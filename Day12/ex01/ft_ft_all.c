/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:11:24 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/25 17:07:18 by hsshih           ###   ########.fr       */
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

void	ft_stdin(int fd_out)
{
	char	buf;

	while (read(0, &buf, 1))
	{
		write(fd_out, &buf, 1);
	}
}

int		ft_print_file(char *str, int fd_out)
{
	int		fd;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd >= 0)
		while (read(fd, &buf, 1) != 0)
			write(fd_out, &buf, 1);
	else
	{
		ft_putstr("cat: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		return (0);
	}
	close(fd);
	return (1);
}

int		ft_is_write_file(char **argv)
{
	int	count;

	count = 1;
	while (argv[count] != (char*)0)
	{
		if (argv[count][0] == '>' && argv[count][1] == '\0')
			return (count);
		count++;
	}
	return (0);
}
