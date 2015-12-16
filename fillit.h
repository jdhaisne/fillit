/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:46:29 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/16 12:23:36 by jdhaisne         ###   ########.fr       */
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

# define BUFF_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino				*arange(t_tetrimino *start);
int						ft_check(char **tab, int *nb_tetrimino_ptr);
int						ft_get_nb_tetrimino(char *s);
char					**read_stdin(char *argv, int *nb_tetrimino_ptr);
t_tetrimino				*ft_splittab(char **tab, int *nb_tetrimino_ptr);
t_tetrimino				*ft_newtetri(char **tetrimino, int num);
char					**solve(t_tetrimino *start, int square_size,\
		char **tab_solved);
char					**create_tab(char **tab, int square_size);

#endif
