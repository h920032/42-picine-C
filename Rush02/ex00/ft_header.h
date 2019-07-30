/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:11:32 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/28 02:01:19 by hugoshih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

enum			e_type
{
	YES,
	NO
};

typedef struct	s_rush
{
	char		*(*r)(int, int);
	char		one[8];
	char		two[9];
	enum e_type	s;
	int			x;
	int			y;
}				t_rush;

void			ft_putchar(char c);
void			ft_putchar_inarray(int *count, char *str, char c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(char *string);
char			*ft_import_stdin(void);
char			*rush_00(int x, int y);
char			*rush_01(int x, int y);
char			*rush_02(int x, int y);
char			*rush_03(int x, int y);
char			*rush_04(int x, int y);

t_rush	g_rush[] =
{
	{&rush_00, "rush-00", "colle-00", NO, 0, 0},
	{&rush_01, "rush-01", "colle-01", NO, 0, 0},
	{&rush_02, "rush-02", "colle-02", NO, 0, 0},
	{&rush_03, "rush-03", "colle-03", NO, 0, 0},
	{&rush_04, "rush-04", "colle-04", NO, 0, 0},
};

#endif
