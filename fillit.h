/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:46:29 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/23 13:55:23 by jdhaisne         ###   ########.fr       */
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

int g_nb_tetrimino;
# define BUFF_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino				*arrange(t_tetrimino *start);
int						ft_check(char **tab);
int						ft_get_nb_tetrimino(char *s);
char					**read_stdin(char *argv);
t_tetrimino				*ft_splittab(char **tab);
t_tetrimino				*ft_newtetri(char **tetrimino, int num);
char					**solve(t_tetrimino *start, int square_size,\
		char **tab_solved);
char					**create_tab(char **tab, int square_size);
void					ft_free_tab(char **tab, int tab_size);
int						ft_check_square(char *s);
int						ft_check_bar(char *s);
int						get_height(char *s);
int						get_width(char *s);
int						ft_is_alone(char *s);
int						ft_check_void_int(char *s);
int						first_test(char *buf);
#endif
