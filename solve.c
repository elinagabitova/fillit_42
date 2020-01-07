#include "fillit.h"

void clear_field(s_figure *tetri, char **field, s_position pos)
{
    int n;

    n = 0;
    while (n < 4)
    {
        if ( field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] == tetri->figure_Alpha)
            field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = '.';
        n++;
    }   
}

int tetri_to_field(s_figure *tetri, char **field, s_position pos)
{
    int n;
    int i = 0;
    
    n = 0;
    while (n < 4)
    {
        if (field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] == '.')
            field[tetri->figure_position[n][1] + pos.y][tetri->figure_position[n][0] + pos.x] = tetri->figure_Alpha;
        else
            return (0);   
        n++;
    }
    while (i < 4)            
    {
        printf("%s\n", field[i]);
        i++;
    }
    printf("\n");
    return (1);
    
}

char  **filling_field(char **field, s_figure *tetri, int count)
{
    s_position pos;
    int n;
    int check;

    n = 0;
    pos.x = 0;
    pos.y = 0;
    while (tetri != NULL)
    {
        check = tetri_to_field(tetri, field, pos);
        if (check == 1)
        {
            pos.x++;
            if (pos.x >= 4)
            {
                pos.x = 0;
                pos.y++;
                if (pos.y >= 4)
                    return (NULL);

            }
            tetri = tetri->next;
        }
        else if (check == 0)
        {
            clear_field(tetri, field, pos);
            pos.x++;
            if (pos.x >= 4)
            {
                pos.x = 0;
                pos.y++;
                if (pos.y >= 4)
                    return(NULL);
            }
        }
    }
    return (field);
}