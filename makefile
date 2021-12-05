NAME = fillit

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra fill_it.c ft_check_file.c ft_redirect.c main.c -L. -lft -o $(NAME)

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all