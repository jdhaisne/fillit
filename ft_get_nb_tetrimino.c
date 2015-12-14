/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:42:36 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/07 16:42:39 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nb_tetrimino(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}
