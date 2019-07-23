/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 19:31:56 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 20:08:28 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (*(s1 + count) == *(s2 + count))
	{
		if (*(s1 + count) == '\0')
		{
			return (0);
		}
		count++;
	}
	return (*(s1 + count) - *(s2 + count));
}

void	ft_sort_wordtab(char **tab)
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
			else if (ft_strcmp(*(tab + max), *(tab + c)) > 0)
				max = c;
			c++;
		}
		temp = tab[r];
		tab[r] = tab[max];
		tab[max] = temp;
		r++;
	}
}
