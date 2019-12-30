#include "fillit.h"
char **increase_field(char **old_field, int old_size)
{
    int i;

    i = 0;
    while (i != old_size)
        free(old_field[i]);
    free(old_field);
    old_size++;
    return(init_field(old_size));
}

int minimum_field(int count)
{
    int min_field;

    min_field = 2 * square(count);
    return(min_field);
}

char **init_field(int count) // taking count of tetriminos
{
    char **field;
    int min_size;
    int i;
    int j;

    j = 0;
    i = 0;
    min_size = minimum_field(count);
    field = (char **)malloc(sizeof(char *) * min_size);
    while (i != min_size)
    {
        field[i] = (char *)malloc(sizeof(char) * min_size);
        while (j != min_size)
        {
            field[i][j] = '.';
            j++;
        }
        i++;
        j = 0;
    }
    return (field);
}

char **field(int count)
{
    char **field;
    field = init_field(count);
    return (field);
}