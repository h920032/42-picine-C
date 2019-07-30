/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:50:19 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/04/01 22:46:17 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_2_H
# define RUSH_2_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	struct s_list	*next;
	char			data;
}				t_list;

char			*ft_concat_list(t_list *list, int len);
void			ft_push_list(t_list **first, char c);
t_list			*ft_create_list(char c);

#endif
