/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:59:35 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/10 14:41:01 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int		ft_check_char(char *s)
{
	int i;
	int hash;
	int point;
	int endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 3)
		return (0);
	return (1);
}

static	int		ft_check_line(char *s)
{
	int i;
	int j;
	int add_5;

	i = 0;
	j = 0;
	add_5 = 4;
	while (s[i] != '\0')
	{
		if (s[i] == '.' || s[i] == '#')
			j++;
		if (j > 4)
			return (0);
		if (s[i] == '\n' && i == add_5)
		{
			j = 0;
			add_5 += 5;
		}
		i++;
	}
	return (1);
}

static	int		ft_check_shape(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' || \
				s[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int				ft_check(char **tab, int *nb_tetrimino_ptr)
{
	int i;

	i = 0;
	while (i < *nb_tetrimino_ptr)
	{
		if (ft_check_char(tab[i]) != 1)
			return (0);
		if (ft_check_line(tab[i]) != 1)
			return (0);
		if (ft_check_shape(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
