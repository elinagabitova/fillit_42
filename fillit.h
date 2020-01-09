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
    char    figure_Alpha;
    struct t_figure *next;
    struct t_figure *prev;
}                s_figure;

typedef struct t_position
{
    int x;
    int y;
}               s_position;

int         validation(char *figure);
int         check_nearly_blocks(char *t, int i);
int         ft_count_char(char *s, char n);
int         read_and_write(int fd, s_figure **tetri);
s_figure    *add_tetrimino(char *figure, s_figure *reading_figure);
s_figure    *add_block(s_position block, s_figure *add_to_figure, int n_block);
s_figure    *correction_func(s_figure *tetri);
int         count_tetriminos(s_figure *start);
char        **init_field(int count);
int         square(int n);
int         minimum_field(int count);
char        **increase_field(char **old_field, int new_size);
char        **field(int count);
int        tetri_to_field(s_figure *tetri, char **field, s_position pos, int size);
int        field_size_test(char **field);
int        filling_field(char **field, s_figure *tetri, int size);
void        print_field(char **field);
void        alpha_to_list(s_figure *start_tetri);
void        clear_full_field(char **field_to_clear, int field_size);


#endif
