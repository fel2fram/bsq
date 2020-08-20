/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othrs_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:28:44 by simoulin          #+#    #+#             */
/*   Updated: 2019/08/21 15:28:48 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_res(int *max, int lg, char *fic, char *carac)
{
	int		fd;
	int		i;
	char	c;

	fd = open(fic, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
	}
	while (read(fd, &c, 1))
	{
		if (max[2] - i / (lg + 1) < max[0] && max[1] - i % (lg + 1) < max[0] &&
			max[2] - i / (lg + 1) >= 0 && max[1] - i % (lg + 1) >= 0)
			write(1, carac + 2, 1);
		else
			write(1, &c, 1);
		i++;
	}
	close(fd);
}

int		change_tab(int *t, int *dims, int i)
{
	t[dims[1]] = (i == 0 ? 0 : t[dims[1] + 1]);
	t[dims[1] + 1] = (i == 0 ? 1 : t[i]);
	t[i] = (i == 0 ? 1 : mi(t[i - 1], t[dims[1] + 1], t[dims[1]]));
	return (1);
}

void	change_max(int *t, int *max, int i, int ligne)
{
	if (t[i] > max[0])
	{
		max[0] = t[i];
		max[1] = i;
		max[2] = ligne;
	}
}
