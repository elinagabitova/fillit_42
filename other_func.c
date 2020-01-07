#include "fillit.h"

void print_field(char **field)
{
    int i;

    i = 0;
    while (field[i])
    {
        printf("%s", field[i]);
        i++;
    }
}
int field_size(char **field)
{
    int size;
    int i;
    
    size = 0;
    i = 0;
    while (*field[i] != '\0')
    {
        size++;
        i++;
    }
    return (size);
}

int square(int n)
{
    int m;
	m = 1;
	while (m * m < n)
		m++;
	//if (m * m != n)
		//m--;  check this!!!
	return (m);
}

s_figure *correction_func(s_figure *tetri)
{
    s_figure *temp;

    temp = tetri;
    tetri = tetri->next;
    tetri->prev = NULL;
    //free(temp);
    return (tetri);
}

int count_tetriminos(s_figure *start)
{
    int count;
    s_figure *temp;

    temp = start;
    count = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    count++;
    free(temp);
    return (count);
}

void alpha_to_list(s_figure *start_tetri)
{
	int		i;

	i = 0;
	while (start_tetri)
	{
		start_tetri->figure_Alpha = 'A' + i;
		start_tetri = start_tetri->next;
		i++;
	}
}