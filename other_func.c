#include "fillit.h"

int square(int n)
{
    int m;
	m = 1;
	while (m * m < n)
		m++;
	if (m * m != n)
		m--;
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