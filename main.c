/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:43:53 by ligeorgi          #+#    #+#             */
/*   Updated: 2019/10/22 13:03:17 by ligeorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

int				main(int argc, char **argv)
{
	t_figure	figures[FIGURES];
	int			fd;
	int			number_of_figures;
	int			size_of_field;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(number_of_figures = read_file(fd, figures)))
	{
		write(1, "error\n", 6);
		return (1);
	}
	size_of_field = fill_field(figures, number_of_figures);
	print_field(figures, number_of_figures, size_of_field);
	close(fd);
	return (0);
}
