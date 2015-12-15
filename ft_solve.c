/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:11:07 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/15 15:49:16 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


void puttab(char **tab);

static char **create_tab(char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	free(tab);
	tab = (char **)malloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = (char*)malloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i] = '.';
			i++;
		}
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

static int	test_pos(t_tetrimino *start, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#' && (start->x + j >= square_size \
						|| start->y + i >= square_size))
				return (0);
			if (start->tetrimino[i][j] == '#' && \
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j= 0;
		i++;
	}
	return (1);
}

static char **placement(t_tetrimino *start, int square_size, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while ( j < 4)
		{
			if (start->tetrimino[i][j] == '#')
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static char **dellete(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if(tab[i][j] == start->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int		place(t_tetrimino *start, int square_size, char **tab)
{
	if(start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((test_pos(start, tab ,square_size)) == 1)
			{
				//place
				tab = placement(start, square_size, tab);
				ft_putstr("tab \n");
				puttab(tab);
				if (place(start->next, square_size, tab) == 1)
					return (1);
				tab = dellete(start, tab);
			}
			if (start->x < square_size)
			{
				start->x++;
			}
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}


char **solve(t_tetrimino *start, int square_size, char **tab_solved)
{
	tab_solved = create_tab(tab_solved, square_size);
	while (place(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		tab_solved = create_tab(tab_solved, square_size);
	}
	return (tab_solved);
}

