/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:30:19 by simoulin          #+#    #+#             */
/*   Updated: 2019/08/21 15:30:21 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>

int		monread(void);
char	*ft_strcpy(char *dest, char *src);
int		main(int ac, char **av);
int		mi(int hg, int bg, int hd);
int		change_tab(int *t, int *dims, int i);
int		taille(char *fic, char *carac, int *lignes);
int		calcule_aux(int *max, int *dims, int fd, char *carac);
int		calcule_tab(int *max, int *dims, int fd, char *carac);
void	print_res(int *max, int lg, char *fic, char *carac);
void	change_max(int *t, int *max, int i, int ligne);
void	main_loop(char *str);

#endif
