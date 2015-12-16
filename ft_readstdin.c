/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readstdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:31:53 by cfelbacq          #+#    #+#             */
/*   Updated: 2015/12/16 11:50:50 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"

static	char	**ft_fill_tab(char **tab, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < ft_get_nb_tetrimino(buf))
	{
		tab[j] = (char*)malloc(sizeof(char) * 19 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 19)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][19] = '\0';
		k = 0;
		j++;
		i = i + 2;
	}
	tab[j] = NULL;
	return (tab);
}

char			**read_stdin(char *argv, int *nb_tetrimino_ptr)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;

	fd = open(argv, O_RDONLY);
	ret = 1;
	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	*nb_tetrimino_ptr = ft_get_nb_tetrimino(buf);
	tmp = (char**)malloc(sizeof(char *) * ft_get_nb_tetrimino(buf) + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_fill_tab(tmp, buf);
	return (tmp);
}

t_tetrimino		*ft_splittab(char **tab, int *nb_tetrimino_ptr)
{
	int			i;
	t_tetrimino	*start;
	t_tetrimino	*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = ft_newtetri(ft_strsplit(tab[0], '\n'), 0);
	ptr = start;
	while (i < *nb_tetrimino_ptr)
	{
		ptr->next = ft_newtetri(ft_strsplit(tab[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}
