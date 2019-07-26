/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:33:55 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/25 17:06:16 by hsshih           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		fd;
	int		re;
	char	buf[BUF_SIZE + 1];

	if (argc - 1 > 1)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	else if (argc - 1 < 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argv[1][0] == '\0')
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while ((re = read(fd, buf, BUF_SIZE)))
	{
		buf[re] = '\0';
		ft_putstr(buf);
	}
	return (0);
}
