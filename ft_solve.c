/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:11:07 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/13 16:24:19 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char **create_tab(char **tab, int square_size)
{
	int i;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = (char*)malloc(sizeof(char));
		i++;
	}
	return (tab);
}

char **solve(t_tetrimino *start, int *nb_tetrimino_ptr)
{
	char **tab_solved;

	tab_solved = NULL;
	if ((tab_solved = create_tab(tab_solved, *nb_tetrimino_ptr)) == NULL)
		return (NULL);
	return (tab_solved);
}

