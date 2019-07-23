/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:24:01 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/22 22:01:02 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPP_H
# define FT_OPP_H
# include "ft_opp_two.h"

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

t_opp			g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod},
	{"", &ft_usage}
};

#endif
