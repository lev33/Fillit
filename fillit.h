/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:44:46 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/22 12:59:22 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define N 4
# define FIGURES 26

typedef struct		s_figure
{
	int				flags;
	char			letter;
	int				dx;
	int				dy;
	int				x;
	int				y;
}					t_figure;

int					read_file(const int fd, t_figure *figures);
t_figure			get_figure(const char *str, const char letter);
int					fill_field(t_figure *figures, int n);
void				print_field(t_figure *f, int n, int size);

#endif
