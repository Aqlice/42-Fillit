#ifndef TETRIS_H
# define TETRIS_H

# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

typedef struct  s_list
{
	char			**tab;
	struct s_list   *next;
	char			piece;
	int			 max;
	char			**result;
	int			 c;
	int			 d;
	int			 p;
	int			 m;
}				   t_list;

t_list  *ft_check_file(const int fd);
int	 ft_redirect_one(char *str, int i);
int	 ft_redirect_two(char *str, int i);
t_list	*free_list(t_list *point);
t_list  *ft_check_file(const int fd);
int	 fill_it(t_list *point, int i, int j);

# define BUFF_SIZE 21
#endif
