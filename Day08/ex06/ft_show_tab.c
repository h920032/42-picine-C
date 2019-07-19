/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:02:42 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/18 21:22:21 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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

void	ft_putnbr(int nb)
{
	int	new_nb;

	if (nb == 0)
	{
		ft_putchar(nb + 48);
	}
	else if (nb > 0)
	{
		new_nb = nb / 10;
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(nb % 10 + 48);
	}
	else
	{
		ft_putchar('-');
		new_nb = 0 - (nb / 10);
		if (new_nb != 0)
		{
			ft_putnbr(new_nb);
		}
		ft_putchar(0 - (nb % 10) + 48);
	}
}

void	ft_print_words_tables(char **tab)
{
	int	count;

	count = 0;
	if (tab == 0 || *tab == 0)
		return ;
	while (*(tab + count) != 0)
	{
		ft_putstr(*(tab + count));
		ft_putchar('\n');
		count++;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	c;
	int	i;

	c = 0;
	while ((par + c)->str != 0)
	{
		i = 0;
		ft_putstr((par + c)->copy);
		ft_putchar('\n');
		ft_putnbr((par + c)->size_param);
		ft_putchar('\n');
		ft_print_words_tables((par + c)->tab);
		c++;
	}
}
