/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:28:26 by simoulin          #+#    #+#             */
/*   Updated: 2019/08/21 15:28:28 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		mi(int hg, int bg, int hd)
{
	if (hg <= bg)
		return (hd <= hg ? hd + 1 : hg + 1);
	return (hd <= bg ? hd + 1 : bg + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
