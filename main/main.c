/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:29:03 by simoulin          #+#    #+#             */
/*   Updated: 2019/08/21 15:36:42 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	erreur(void)
{
	write(1, "map error\n", 10);
}

void	main_loop(char *str)
{
	int		fd;
	int		*t;
	int		dimensions[2];
	int		max[3];
	char	carac[3];

	max[0] = -1;
	dimensions[0] = 0;
	if ((dimensions[1] = taille(str, carac, dimensions)) < 1)
		erreur();
	else
	{
		fd = open(str, O_RDONLY);
		if (taille >= 0 && calcule_tab(max, dimensions, fd, carac))
			erreur();
		else
			print_res(max, dimensions[1], str, carac);
		close(fd);
	}
}

int		monread(void)
{
	int		fd;
	char	c;
	int		lignes;

	lignes = 0;
	fd = open("zzz", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (read(0, &c, 1) && c >= '0' && c <= '9')
	{
		lignes = (lignes * 10) + c - '0';
		write(fd, &c, 1);
	}
	write(fd, &c, 1);
	while (lignes > -1)
	{
		read(0, &c, 1);
		write(fd, &c, 1);
		if (c == '\n')
			lignes--;
	}
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	char	*lecture;

	if (ac == 1)
	{
		if (monread() < 0)
		{
			erreur();
			return (0);
		}
		main_loop("zzz");
		i = open("zzz", O_RDWR | O_CREAT | O_TRUNC, 0777);
		close(i);
	}
	i = 1;
	while (i < ac)
	{
		main_loop(av[i]);
		if (i < ac - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
