#include "fillit.h"

int ft_count_char(char *s, char n)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == n)
				count++;
			i++;
		}
	}
	return (count);
}
int check_nearly_blocks(char *t, int i)
{
    int y;

    y = 5;
    if (t[i] == '\n')
        y++;
    if (i > 0 && i < 12)
        if (t[i + y] == '#' || t[i + 1] == '#' || t[i - 1] == '#')
            return (1);
    if (i == 0)
        if (t[i + y] == '#' || t[i + 1] == '#')
            return (1); 
    if (i == 15)
    {
        if (t[i - y] == '#' || t[i + 1] == '#')
            return (1);
    }
    else
    {
        if (t[i + 1] == '#' || t[i - 1] == '#' || t[i - y] == '#')
            return (1);
    }
    return (0);
}
int validation(char *figure)
{
    int check;
    int i;

    i = 0;
    if (ft_count_char(figure, '#') != 4)
        return (0);
    if (ft_count_char(figure, '*') != 12)
        return (0);
    while (figure[i] != '\0')
    {
        if (figure[i] == '#')
        {
            check = check_nearly_blocks(figure, i);
            if (check == 0)
                return (check);
        }
        i++;
    }
    return (check);
}