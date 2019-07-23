/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:09:12 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 20:17:54 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		c;
	int		r;
	int		max;

	r = 0;
	if (tab == 0)
		return ;
	while (*(tab + r) != 0)
	{
		max = -1;
		c = r;
		while (*(tab + c) != 0)
		{
			if (max == -1)
				max = c;
			else if (cmp(*(tab + max), *(tab + c)) > 0)
				max = c;
			c++;
		}
		temp = tab[r];
		tab[r] = tab[max];
		tab[max] = temp;
		r++;
	}
}
