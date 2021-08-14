/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:27 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/24 12:47:03 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		min_y(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '#')
		i++;
	return (i / (N + 1));
}

static int		min_x(const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (str[j * (N + 1) + i] == '#')
				return ((j * (N + 1) + i) % (N + 1));
			j++;
		}
		i++;
	}
	return (0);
}

static int		max_y(const char *str)
{
	int	i;

	i = N * (N + 1) - 1;
	while (str[i] != '#')
		i--;
	return (i / (N + 1));
}

static int		max_x(const char *str)
{
	int	i;
	int	j;

	i = N - 1;
	while (i >= 0)
	{
		j = N - 1;
		while (j >= 0)
		{
			if (str[j * (N + 1) + i] == '#')
				return ((j * (N + 1) + i) % (N + 1));
			j--;
		}
		i--;
	}
	return (N);
}

t_figure		get_figure(const char *str, const char letter)
{
	t_figure	f;
	int			x;
	int			y;
	int			xf;
	int			yf;

	f.flags = 0;
	f.letter = letter;
	xf = min_x(str);
	yf = min_y(str);
	f.dx = max_x(str) - xf + 1;
	f.dy = max_y(str) - yf + 1;
	y = 0;
	while (y < f.dy)
	{
		x = 0;
		while (x < f.dx)
		{
			if (str[(xf + x) + (yf + y) * (N + 1)] == '#')
				f.flags |= (1 << (x + y * N));
			x++;
		}
		y++;
	}
	return (f);
}
