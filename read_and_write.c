#include "fillit.h"
s_figure *figures_to_zero_pos(s_figure *tetri)
{
    s_position pos;
    int n;

    n = 0;
    pos.x = tetri->figure_position[0][0];
    pos.y = tetri->figure_position[0][1];
    while (n < 4)
    {    
        tetri->figure_position[n][0] = tetri->figure_position[n][0] - pos.x;
        tetri->figure_position[n][1] = tetri->figure_position[n][1] - pos.y;
        n++;
    }
    return (tetri);
}

s_figure *add_block(s_position block, s_figure *add_to_figure, int n_block)
{
    add_to_figure->figure_position[n_block][0] = block.x;
    add_to_figure->figure_position[n_block][1] = block.y;
    add_to_figure->next = NULL;
    return (add_to_figure);
}

s_figure *add_tetrimino(char *figure, s_figure *reading_figure)
{
    s_figure        *current_tetrimino;
    s_position      tetriminos_position;
    int             n;

    n = 0;
    tetriminos_position.x = 0;
    tetriminos_position.y = 0;
    current_tetrimino = malloc(sizeof(s_figure));
    if (!(current_tetrimino))
        return (NULL);
    while (figure && n != 4)
    {
        if (*figure == '\n')
        { 
           tetriminos_position.y++;
           tetriminos_position.x = -1;
        }
        if (*figure == '#')
        {
            add_block(tetriminos_position, current_tetrimino, n);
            n++;
        }
        tetriminos_position.x++;
        figure++;
    }
    return (current_tetrimino);
}

int read_and_write(int fd, s_figure **tetri)
{
    char        *buf;
    int         readed;
    s_figure    *reading_tetrimino;
    s_figure    *temp;
    char        alpha;
    int count;
    int check;

    alpha = 64;
    count = 0;
    reading_tetrimino = NULL;
    buf = (char *)(malloc(sizeof(char) * 22));
    while ((readed = read(fd, buf, 21)))
    {
        buf[readed] = '\0';
        check = validation(buf);
        if (check)
        {
            temp = *tetri;
            (*tetri)->next = add_tetrimino(buf, reading_tetrimino);
            (*tetri) = (*tetri)->next;
            figures_to_zero_pos(*tetri);
            (*tetri)->prev = temp;
        }
        else
            printf("Wrong tetrimino");
    }
    (*tetri)->next = NULL;
    //free(temp);
    return (0);
}
char **increase_field(char **old_field, int new_size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    //clear_full_field(old_field, new_size);
    old_field = (char **)malloc(sizeof(char *) * new_size);
    while (i < new_size)
    {
        old_field[i] = (char *)malloc(sizeof(char) * new_size);
        i++;
    }
    i = 0;
    while (j < new_size)
    {
        while (i < new_size)
        {
            old_field[j][i] = '.';
            i++;
            
        }
        j++;
        i = 0;
    }
    return (old_field);
}
int main(int argc, char **argv)
{
    int fd;
    s_figure *tetri;
    s_figure *start;
    s_figure *temp;
    char **field_new;
    int size;

    tetri = malloc(sizeof(s_figure));
    tetri->prev = NULL;
    start = tetri;
    fd = open(argv[1], O_RDONLY);
    read_and_write(fd, &tetri);
    start = correction_func(start);
    temp = start;
    field_new = field(count_tetriminos(start));
    alpha_to_list(start);
    size = field_size_test(field_new);
    while (!(filling_field(field_new, start, size)))
    {
        field_new = increase_field(field_new, ++size);
        start = temp;
    }
    return (0);
}