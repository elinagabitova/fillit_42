#include "fillit.h"

void clear_field(s_figure *tetri, char **field, s_position pos)
{
    int n;

    n = 0;
    while (n < 4)
    {
        field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = '.';
        n++;
    }   
}

int tetri_to_field(s_figure *tetri, char **field, s_position pos)
{
    int n;
    
    n = 0;
    while (n < 4)
    {
        if (field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] == '.')
            field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = tetri->figure_Alpha;
        else
            return (0);   
        n++;
    }
    return (1);
    
}

void filling_field(char **field, s_figure *tetri, int count) //not count but field size;
{
    s_position pos;
    int n;
    int check;

    n = 0;
    while (tetri != NULL) //moving tetrimino coordinates to 00 -> put as function
    {
        pos.x = tetri->figure_position[0][0];
        pos.y = tetri->figure_position[0][1];
        while (n < 4)
        {    
            tetri->figure_position[n][0] = tetri->figure_position[n][0] - pos.x;
            tetri->figure_position[n][1] = tetri->figure_position[n][1] - pos.y;
            n++;
        }
        tetri = tetri->next;
    }
    while (tetri->prev != NULL) //moving tetri pointer to start position;
        tetri = tetri->prev;
    while (tetri != NULL)
    {
        check = tetri_to_field(tetri, field, pos);
        if (check == 1)
            pos.x++;
        else if (check == 0)
        {
            clear_field(tetri, field, pos);
            pos.x++;
        }
        if (pos.x == count - 1)
        {
            pos.x = 0;
            pos.y++; 
        }
        tetri = tetri->next;
    }
}