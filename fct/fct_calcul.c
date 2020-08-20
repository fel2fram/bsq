/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:28:36 by simoulin          #+#    #+#             */
/*   Updated: 2019/08/21 15:28:38 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		calcule_aux(int *max, int *dims, int fd, char *carac)
{
	int		i;
	char	c;
	int		ligne;
	int		*t;

	i = dims[1] + 2;
	if (!(t = malloc(sizeof(int) * (dims[1] + 2))))
		return (-1);
	while (i > 0)
		t[--i] = 0;
	i = 0;
	ligne = 0;
	while (read(fd, &c, 1))
	{
		(c == carac[1] ? t[i] = 0 : 0);
		(c == '\n' ? ligne++ : 0);
		if (c != '\n' && c != carac[1] && change_tab(t, dims, i))
			change_max(t, max, i, ligne);
		if ((c != carac[0] && c != carac[1] && c != '\n')
			|| (c == '\n' && (i % dims[1] || !i)))
			return (-1);
		i = (c == '\n' ? 0 : i + 1);
	}
	free(t);
	return (ligne - dims[0]);
}

int		calcule_tab(int *max, int *dims, int fd, char *carac)
{
	char	c;

	while (read(fd, &c, 1) && c != '\n')
		c = c;
	return (calcule_aux(max, dims, fd, carac));
}

int		taille(char *fic, char *carac, int *lignes)
{
	int		fd;
	int		i;
	char	c;

	if ((fd = open(fic, O_RDONLY)) < 0 || read(fd, &c, 1) < 0)
		return (-1);
	i = 0;
	while (c >= '0' && c <= '9')
	{
		*lignes = (*lignes * 10) + c - '0';
		read(fd, &c, 1);
	}
	carac[0] = c;
	while (i++ < 2 && read(fd, carac + i, 1))
		if (carac[i] == '\n')
			return (-1);
	read(fd, &c, 1);
	if (c != '\n' || carac[0] == carac[1] ||
		carac[2] == carac[1] || carac[2] == carac[0])
		return (-1);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
		i++;
	close(fd);
	return (i);
}
