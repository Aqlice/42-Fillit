#include "tetris.h"

t_list	*free_list(t_list *point)
{
	t_list *tmp;

	while (point)
	{
		tmp = point->next;
		if (point->tab)
			free(point->tab);
		point = tmp;
	}
	return (point);
}

int	 ft_get_next_piece(char *str)
{
	int i;
	int ret;

	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	ret = ft_redirect_one(str, i);
	if (ret == 0)
		ret = ft_redirect_two(str, i);
	return (ret);
}

int	 ft_check_piece(char *str)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
			j++;
		if (str[i] == '#')
			c++;
		i++;
	}
	if (str[0] != '\n' || str[5] != '\n' || str[10] != '\n' || str[15] !='\n' || str[20] != '\n')
		return (0);
	if (j != 12 || c != 4)
		return (0);
	return (ft_get_next_piece(str));
}

int ft_check_first(char *buff)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (buff[i])
	{
		if (buff[i] == '.')
			j++;
		if (buff[i] == '#')
			c++;
		i++;
	}
	if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n' || buff[19] != '\n')
		return (0);
	if (j != 12 || c != 4)
		return (0);
	return (ft_get_next_piece(buff));
}

t_list  *ft_first_check(int fd)
{
	char	buff[21];
	t_list  *point;
	int ret;

	point = NULL;
	ret = read(fd, buff, 20);
	buff[ret] = 0;
	if (!(ft_check_first(buff)))
		return (0);
	if ((point = (t_list*)malloc(sizeof(t_list))))
	{
		point->next = NULL;
		point->tab = ft_strsplit(buff, '\n');
	}
	return (point);
}

t_list  *ft_check_file(const int fd)
{
	int	 ret;
	char	buff[BUFF_SIZE + 1];
	t_list  *point;
	t_list  *begin;
	t_list  *previous;

	begin = NULL;
	previous = NULL;
	if (!(begin = ft_first_check(fd)))
		return (NULL);
	previous = begin;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == 21)
		{
			buff[ret] = 0;
			if (!(ft_check_piece(buff)))
				return (NULL);
			if (!(point = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			point->next = NULL;
			point->tab = ft_strsplit(buff, '\n');
			if (previous)
				previous->next = point;
			previous = point;
		}
		else
		{

			free_list(begin);
			return (NULL);
		}
	}
	return (begin);
}