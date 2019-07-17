/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:51:20 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/16 22:54:55 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb, int time)
{
	int		new_nb;
	char	*hexadecimals;

	hexadecimals = "0123456789abcdef";
	if (nb == 0)
	{
		ft_putchar(*(hexadecimals + nb));
		if (time < 8)
		{
			time++;
			ft_putnbr(0, time);
		}
	}
	else if (nb < 0)
		ft_putnbr(256 + nb, 7);
	else if (nb > 0)
	{
		new_nb = nb / 16;
		if (time < 8)
		{
			time++;
			ft_putnbr(new_nb, time);
		}
		ft_putchar(*(hexadecimals + nb % 16));
	}
}

void	ft_print_part(char *t, int *a, int *c, int *s)
{
	ft_putnbr(*a, 1);
	ft_putchar(':');
	ft_putchar(' ');
	*c = 0;
	while (*c < 16 && *c < *s)
	{
		ft_putnbr(*(t + *a + *c), 7);
		if (*c % 2 == 1)
			ft_putchar(' ');
		*c = *c + 1;
	}
	while (16 > *c)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (*c % 2 == 1)
			ft_putchar(' ');
		*c = *c + 1;
	}
	ft_putchar(' ');
	*c = 0;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		s;
	int		a;
	int		c;
	char	*t;

	s = size;
	a = 0;
	t = addr;
	while (s > 0)
	{
		ft_print_part(t, &a, &c, &s);
		while (c < 16 && c < s)
		{
			if (*(t + a + c) >= 32 && *(t + a + c) <= 126)
				ft_putchar(*(t + a + c));
			else
				ft_putchar('.');
			c++;
		}
		ft_putchar('\n');
		s = s - 16;
		a = a + 16;
	}
	return (addr);
}
