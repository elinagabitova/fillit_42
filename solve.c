#include "fillit.h"

void clear_field(s_figure *tetri, char **field, s_position pos, int size)
{
    int n;

    n = 0;
    while (n < 4)
    {   
        if (tetri->figure_position[n][1] + pos.y < size && tetri->figure_position[n][0] + pos.x < size)
        {
            if (field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] == tetri->figure_Alpha)
                field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = '.';
        }
        n++;
    } 
}

int tetri_to_field(s_figure *tetri, char **field, s_position pos, int size)
{
    int n;
    
    n = 0;
    while (n < 4)
    {    
        if (tetri->figure_position[n][1] + pos.y < size && tetri->figure_position[n][0] + pos.x < size)
        {
            if (field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] == '.')
                field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = tetri->figure_Alpha;
            else
                return (0);   
        }
        else
            return (0);
        n++;
    }
    return (1);    
}

int  filling_field(char **field, s_figure *tetri, int size)
{
    s_position pos;
    int n;
    int check;

    n = 0;
    pos.x = 0;
    pos.y = 0;
    while (tetri != NULL)
    {
        check = tetri_to_field(tetri, field, pos, size);
        if (check == 1)
        {
            tetri = tetri->next;
            pos.x = 0;
            pos.y = 0;
            while (n < size)
            {
                printf("%s\n", field[n]);
                n++;
            }
            printf("\n");
            n = 0;
        }

        else if (check == 0)
        {
            clear_field(tetri, field, pos, size);
            pos.x++;
            if (pos.x >= size)
            {   
                pos.x = 0;
                pos.y++;
                if (pos.y >= size)
                {
                    printf("zakonchilo\n");
                    return (0);
                }
            }
        }
    }
    return (1);
}