/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:03:36 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/09 15:04:49 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void ft_putlst(t_tetrimino *start)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(start != NULL)
	{
		printf("\t tetrimino %d \n", i);
		i++;
		while(j < 4)
		{
		printf("%s \n", start->tetrimino[j]);
		j++;
		}
		j = 0;
		printf("letter = %c", start->letter);
		printf("x = %d", start->x);
		printf("y = %d", start->y);
		start = start->next;
	}
}
