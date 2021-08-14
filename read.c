/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:46:08 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/24 12:53:44 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

static int		is_touch(const char *str, int i)
{
	int			near;

	near = 0;
	if ((i + 1) < N * (N + 1) && str[i + 1] == '#')
		near++;
	if ((i - 1) >= 0 && str[i - 1] == '#')
		near++;
	if ((i + (N + 1)) < N * (N + 1) && str[i + (N + 1)] == '#')
		near++;
	if ((i - (N + 1)) >= 0 && str[i - (N + 1)] == '#')
		near++;
	return (near);
}

static int		check_blocks(const char *str)
{
	int			near;
	int			res;
	int			i;

	res = 0;
	i = 0;
	while (i < N * (N + 1))
	{
		if (str[i] == '#')
		{
			if (!(near = is_touch(str, i)))
				return (0);
			res += near;
		}
		i++;
	}
	return ((N == 3 && res == 4) || (N == 4 && (res == 6 || res == 8))
								|| (N == 5 && (res == 8 || res == 10)));
}

static int		check_buf(const char *str)
{
	int			i;
	int			blocks;

	blocks = 0;
	i = 0;
	while (i < N * (N + 1))
	{
		if (i % (N + 1) < N)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#')
				blocks++;
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (blocks != N)
		return (1);
	if (!check_blocks(str))
		return (1);
	return (0);
}

int				read_file(const int fd, t_figure *figures)
{
	char		buf[N * (N + 1) + 1];
	int			n;
	int			n_last;
	int			i;
	char		letter;

	letter = 'A';
	i = 0;
	while ((n = read(fd, buf, N * (N + 1) + 1)) >= N * (N + 1))
	{
		if (i == FIGURES)
			return (0);
		if (n == N * (N + 1) + 1 && buf[n - 1] != '\n')
			return (0);
		if (check_buf(buf))
			return (0);
		figures[i++] = get_figure(buf, letter++);
		n_last = n;
	}
	if (n != 0 || (n == 0 && n_last == N * (N + 1) + 1))
		return (0);
	return (letter - 'A');
}
