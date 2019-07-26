/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoshih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:17:22 by hugoshih          #+#    #+#             */
/*   Updated: 2019/07/25 22:44:57 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# define BUF_SIZE 30
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			data;
	struct s_list	*next;
}				t_list;

t_list			*ft_create_elem(char data);
int				ft_atoi_me(char *string);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_print_list(t_list *b, int offset);
void			ft_list_push_back(t_list **begin_list, char data);
void			ft_list_clear(t_list **begin_list);
void			ft_short(int *nl, t_list *data[10], char *buf, int *count);
void			ft_stdin(void);
void			ft_filein(int fd);
int				ft_is_num(char *str);
void			ft_output(int var[4], char *str);
void			ft_print_size(int is_only, int offset, char *str, int index);
void			ft_output_file(int var[3], char *str);
void			ft_print_file(int is_only, char *str, int index);
void			ft_print_size_stdin(int offset);
void			ft_print_filein(char **argv, int argc);
void			ft_print(char **argv, int argc);
void			ft_print_error(void);

#endif
