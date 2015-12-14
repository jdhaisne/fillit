/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:46:29 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/13 14:58:03 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int 				x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino *arange(t_tetrimino *start);
int			ft_check(char **tab, int *nb_tetrimino_ptr);
int			ft_get_nb_tetrimino(char *s);
char		**read_stdin(char *argv, int *nb_tetrimino_ptr);
t_tetrimino *ft_splittab(char **tab, int *nb_tetrimino_ptr);
t_tetrimino	*ft_newtetri(char **tetrimino, int num);


#endif
