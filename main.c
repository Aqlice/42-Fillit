#include "tetris.h"

void	usage(void)
{
	ft_putendl("Usage : ./fillit [file]");
}

void	print_result(t_list *point, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(point->result[i]);
		free(point->result[i]);
		i++;
	}
	free(point->result);
	free(point);
}

void	fill_point(t_list *point, int size, char **result)
{
	int i;
	int j;
	char piece;

	piece = 'A';
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			result[i][j] = '.';
			j++;
		}
		result[i][j] = 0;
		i++;
	}
	while (point)
	{
		point->max = size;
		point->result = result;
		point->piece = piece;
		point = point->next;
		piece++;
	}
}

void	failed_square(t_list *point, int size)
{
	int i;

	i = 0;;
	while (i < size)
	{
		free(point->result[i]);
		i++;
	}
	free(point->result);
}

void	fill_size(t_list *point, int size)
{
	char	**result;
	int	 i;
	int	 j;

	i = 0;
	if (!(result = (char**)malloc(sizeof(char*) * size)))
		return ;
	while (i < size)
	{
		if (!(result[i] = (char*)malloc(sizeof(char) * (size + 1))))
		{
			j = 0;
			while (j < i)
			{
				free(result[j]);
				j++;
			}
			free(result);
			return ;
		}
		i++;
	}
	fill_point(point, size, result);
}

int	 check_size_min(t_list *point)
{
	int	 i;
	int	 size;

	size = 2;
	i = 0;
	while (point)
	{
		i++;
		point = point->next;
	}
	while ((size * size) < (i * 4))
		size++;
	return (size);
} 

int	 main(int argc, char **argv)
{
	t_list  *point;
	int	 size;
	int	 ft;

	if (argc != 2)
	{
		usage();
		return (0);
	}
	if (!(ft = open(argv[1],O_RDONLY)))
		return (0);
	if (!(point = ft_check_file(ft)))
	{
		ft_putendl("error");
		return (0);
	}
	size = check_size_min(point);
	fill_size(point, size);
	while (!(fill_it(point, 0, 0)))
	{
		failed_square(point, size);
		size++;
		fill_size(point, size);
	}
	print_result(point, size);
	return (0);
}