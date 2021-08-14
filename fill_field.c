/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:07 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/24 18:05:20 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static void		set_zero(t_figure *f, int *field, int z, int size)
{
	int i;
	int j;

	i = 0;
	while (i < f->dx)
	{
		j = 0;
		while (j < f->dy)
		{
			if ((f->flags >> (i + N * j)) & 1)
				field[z + i + size * j] = 0;
			j++;
		}
		i++;
	}
}

static void		set_figure(t_figure *f, int *field, int z, int size)
{
	int i;
	int j;

	i = 0;
	while (i < f->dx)
	{
		j = 0;
		while (j < f->dy)
		{
			if ((f->flags >> (i + N * j)) & 1)
				field[z + i + size * j] = 1;
			j++;
		}
		i++;
	}
}

static int		is_free(t_figure *f, int *field, int z, int size)
{
	int i;
	int j;

	i = 0;
	while (i < f->dx)
	{
		j = 0;
		while (j < f->dy)
		{
			if (((f->flags >> (i + N * j)) & 1) && field[z + i + size * j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		fill(t_figure *f, int n, int *field, int size)
{
	if (!n)
		return (1);
	f->y = -1;
	while (++f->y < size - f->dy + 1)
	{
		f->x = -1;
		while (++f->x < size - f->dx + 1)
		{
			if (is_free(f, field, f->x + size * f->y, size))
			{
				set_figure(f, field, f->x + size * f->y, size);
				if (fill(++f, n - 1, field, size))
					return (1);
				else
				{
					f--;
					set_zero(f, field, f->x + size * f->y, size);
				}
			}
		}
	}
	return (0);
}

int				fill_field(t_figure *figures, int n)
{
	int		size;
	int		*field;

	size = 2;
	while (size * size < n * N)
		size++;
	field = (int*)ft_memalloc(sizeof(int) * size * size);
	while (!fill(figures, n, field, size))
	{
		free(field);
		size++;
		field = (int*)ft_memalloc(sizeof(int) * size * size);
	}
	free(field);
	return (size);
}
