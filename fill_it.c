#include "tetris.h"

int	 place_c(t_list *point)
{
	int c;
	int d;

	c = 0;
	d = 0;
	while (point->tab[c][d] != '#')
	{
		if (d == 3)
		{
			c++;
			d = -1;
		}
		d++;
	}
	return (c);
}

int	 place_d(t_list *point)
{
	int c;
	int d;

	c = 0;
	d = 0;
	while (point->tab[c][d] != '#')
	{
		if (d == 3)
		{
			c++;
			d = -1;
		}
		d++;
	}
	return (d);
}
int	 place_piece(t_list *point, int i, int j)
{
	int c;
	int d;

	c = place_c(point);
	d = place_d(point);
	while (c < 4)
	{
		while (d < 4)
		{
			if (point->tab[c][d] == '#')
				point->result[i][j] = point->piece;
			d++;
			j++;
		}
		d = 0;
		j = j - 4;
		i++;
		c++;
	}
	return (1);
}

void	delete_piece(t_list *point)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (i < point->max)
	{
		while (j < point->max)
		{
			if (point->result[i][j] == point->piece)
			{
				point->result[i][j] = '.';
				c++;
			}
			j++;
			if (c == 4)
				return ;
		}
		j = 0;
		i++;
	}
}

int	 check_fill(t_list *point, int i, int j)
{
	point->p = i;
	point->m = j;
	point->c = place_c(point);
	point->d = place_d(point);
	while (point->c < 4)
	{
		while (point->d < 4)
		{
			if (point->tab[point->c][point->d] == '#')
			{
				if (!(i >= 0 && i < point->max && j >= 0 && j < point->max))
					return (0);
				if (point->result[i][j] != '.')
					return (0);
			}
			j++;
			point->d++;
		}
		point->d = 0;
		point->c++;
		i++;
		j = j - 4;
	}
	return (place_piece(point, point->p, point->m));
}

int	 fill_it(t_list *point, int i, int j)
{
	int ret;

	ret = 0;
	i = 0;
	if (!(point))
		return (1);
	i = 0;
	while (i < point->max)
	{
		j = 0;
		while (j < point->max)
		{
			if (point->result[i][j] == '.')
				if ((ret = check_fill(point, i, j)))
				{
					if (fill_it(point->next, 0, 0))
						return (1);
					else
						delete_piece(point);
				}
			j++;
		}
		i++;
	}
	return (0);
}