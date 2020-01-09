#include "fillit.h"

void clear_full_field(char **field_to_clear, int field_size)
{
    int i;

    i = 0;
    while (i < (field_size - 1))
    {
        free(field_to_clear[i]);
        i++;
    }
    i = 0;
    free(field_to_clear);
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
    int i;

    i = 0;
    char **field;
    field = init_field(count);
    return (field);
}