/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toberon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:35:48 by toberon           #+#    #+#             */
/*   Updated: 2019/10/21 15:35:49 by toberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct t_figure
{
    int     figure_position[4][2];
    char    figure_type;
    struct t_figure *next;
    struct t_figure *prev;
}                s_figure;

typedef struct t_position
{
    int x;
    int y;
}               s_position;

int validation(char *figure);
int check_nearly_blocks(char *t, int i);
int ft_count_char(char *s, char n);
int read_and_write(int fd, s_figure **tetri);
s_figure *add_tetrimino(char *figure, s_figure *reading_figure);
s_figure *add_block(s_position block, s_figure *add_to_figure, int n_block);

#endif
