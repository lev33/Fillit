/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:45 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/22 13:43:40 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static char		*new_field(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[(size + 1) * y + x] = '.';
			x++;
		}
		str[(size + 1) * y + size] = '\n';
		y++;
	}
	return (str);
}

void			print_field(t_figure *f, int n, int size)
{
	char	*str;
	int		x;
	int		y;

	str = new_field(size);
	while (n > 0)
	{
		y = 0;
		while (y < f->dy)
		{
			x = 0;
			while (x < f->dx)
			{
				if ((f->flags >> (x + y * N) & 1))
					str[(size + 1) * (f->y + y) + (f->x + x)] = f->letter;
				x++;
			}
			y++;
		}
		f++;
		n--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}
