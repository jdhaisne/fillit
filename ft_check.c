/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:59:35 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/23 16:25:49 by jdhaisne         ###   ########.fr       */
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
	if (hash != 4 || point != 12 || endline != 4)
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
	int height;
	int width;

	i = 0;
	height = get_height(s);
	width = get_width(s);
	if (ft_is_alone(s) == 0)
		return (0);
	if (ft_check_void_int(s) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}

int				ft_check(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetrimino)
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

int				first_test(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			j++;
		if (j == 4)
		{
			if (buf[i + 1] != '\n' && buf[i + 1] != '\0')
				return (0);
			if (buf[i + 1] == '\n')
				i++;
			j = 0;
		}
		i++;
	}
	return (1);
}
