/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:30:04 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/18 10:30:58 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	char	**arrange_up(int i_min, char **tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i + i_min < 4)
	{
		tab[i] = tab[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tab[i] = "....\0";
		i++;
	}
	return (tab);
}

static	char	**arrange_left(int j_min, char **tab)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + j_min] != '\0')
		{
			tab[i][j] = tab[i][j + j_min];
			j++;
		}
		tmp = j_min;
		while (tmp > 0 && tmp > 0)
		{
			tab[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static int		get_i_min(char **tab)
{
	int i;
	int j;
	int i_min;

	i = 0;
	j = 0;
	i_min = 0;
	while (i < 4)
	{
		while (tab[i][j] != '#' && tab[i][j] != '\0')
			j++;
		if (j == 4)
			i_min++;
		else
			return (i_min);
		j = 0;
		i++;
	}
	return (i_min);
}

static int		get_j_min(char **tab)
{
	int i;
	int j;
	int j_min;

	i = 0;
	j = 0;
	j_min = 4;
	while (i < 4)
	{
		while (tab[i][j] != '#' && tab[i][j] != '\0')
			j++;
		j_min = (j < j_min) ? j : j_min;
		j = 0;
		i++;
	}
	return (j_min);
}

t_tetrimino		*arrange(t_tetrimino *start)
{
	t_tetrimino *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = arrange_left(get_j_min(tmp->tetrimino),\
				tmp->tetrimino);
		tmp->tetrimino = arrange_up(get_i_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}
