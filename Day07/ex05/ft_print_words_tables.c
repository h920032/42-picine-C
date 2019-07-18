/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:23:09 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/17 23:44:39 by hugoshih         ###   ########.fr       */
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
