/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_two.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:38:11 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 21:49:16 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_TWO_H
# define FT_HEADER_TWO_H

typedef struct	s_opp
{
	char	symbol[2];
	int		(*f)(int, int);
}				t_opp;

int				ft_sub(int a, int b)
{
	if (a < 0 && b > 0 && -2147483648 + b > a)
		return (0);
	else if (a > 0 && b < 0 && 2147483647 + b < a)
		return (0);
	else if (a == 0 && b == -2147483648)
		return (0);
	return (a - b);
}

int				ft_add(int a, int b)
{
	if (a > 0 && b > 0 && 2147483647 - b < a)
		return (0);
	else if (a < 0 && b < 0 && -2147483648 - b > a)
		return (0);
	return (a + b);
}

int				ft_mul(int a, int b)
{
	if (((a > 0 && b > 0) || (a < 0 && b < 0)) && 2147483647 / b < a)
		return (0);
	else if (a > 0 && b < 0 && -2147483648 / b < a)
		return (0);
	else if (a < 0 && b > 0 && -2147483648 / b > a)
		return (0);
	return (a * b);
}

#endif
