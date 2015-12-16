/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:50:20 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/16 11:58:48 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void	puttab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_tetrimino *start;
	char		**tab;
	int			*nb_tetrimino_ptr;
	int			nb_tetrimino;

	start = NULL;
	tab = NULL;
	nb_tetrimino = 0;
	nb_tetrimino_ptr = &nb_tetrimino;
	if (argc != 2)
		return (0);
	tab = read_stdin(argv[1], nb_tetrimino_ptr);
	if (ft_check(tab, nb_tetrimino_ptr) == 0)
	{
		ft_putstr("ERROR");
		return (0);
	}
	start = ft_splittab(tab, nb_tetrimino_ptr);
	arange(start);
	puttab(solve(start, 2, NULL));
	return (1);
}
