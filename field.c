#include "fillit.h"

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

    i = 0;
    min_size = minimum_field(count);
    field = (char **)malloc(sizeof(char *) * min_size + 1);
    field[min_size] = NULL;
    while (field[i] != NULL)
    {
        field[i] = (char *)malloc(sizeof(char) * min_size + 1);
        field[i][min_size] = '\0';
        i++;
    }
    return (field);
}

int main()
{
    char **field;
    int i;
    int j;

    i = 0;
    j = 0;
    field = init_field(4);
    printf("%s", field[i]);
    while (field[i] != NULL)
    {
        write(1, "!", 1);
        while(field[i][j] != '\0')
        {
            field[i][j] = '1';
            printf("%c", field[i][j]);
            j++;
        }
        printf("%s", field[i]);
        i++;
    }
    return (0);
}