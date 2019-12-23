#include "fillit.h"

s_figure *add_block(s_position block, s_figure *add_to_figure, int n_block)
{
    add_to_figure->figure_position[n_block][0] = block.x;
    add_to_figure->figure_position[n_block][1] = block.y;
    add_to_figure->next = NULL;
   //printf("%d", add_to_figure->figure_position[n_block][0]);
   // printf("%d\n", add_to_figure->figure_position[n_block][1]);
    return (add_to_figure);
}

s_figure *add_tetrimino(char *figure, s_figure *reading_figure) //adding tetrimino's coordinates to struct
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

int read_and_write(int fd, s_figure **tetri) //reading tetriminos and return count of them
{
    char        *buf;
    int         readed;
    s_figure    *reading_tetrimino;
    s_figure    *temp;
    int count;
    int check;

    count = 0;
    reading_tetrimino = NULL;
    buf = (char *)(malloc(sizeof(char) * 22));
    while ((readed = read(fd, buf, 21)))
    {
        buf[readed] = '\0';
        check = validation(buf);
        if (check)
        {
            temp = (*tetri);
            (*tetri)->next = add_tetrimino(buf, reading_tetrimino);
            (*tetri) = (*tetri)->next;
            (*tetri)->prev = temp;
            //printf ("\n");
        }
        //else
           // printf("Wrong tetrimino");
    }
    (*tetri)->next = NULL;
    free(temp);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;
    s_figure *tetri;
    s_figure *start;

    tetri = malloc(sizeof(s_figure));
    tetri->prev = NULL;
    start = tetri;
    fd = open(argv[1], O_RDONLY);
    read_and_write(fd, &tetri);
    start = start->next;
    printf("%d", start->figure_position[1][0]);
    printf("%d\n", start->figure_position[1][1]);
    start = start->next;
    printf("%d", tetri->figure_position[1][0]);
    printf("%d", tetri->figure_position[1][1]);
    return (0);
}