int	 ft_redirect_one(char *str, int i)
{
	if (i + 6 <= 19 && str[i + 1] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
		return (1);
	if (i + 15 <= 19 && str[i + 5] == '#' && str[i + 10] == '#' && str[i + 15] == '#')
		return (2);
	if (i + 3 <= 19 && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 3] == '#')
		return (3);
	if (i + 5 <= 19 && str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		return (4);
	if (i + 11 <= 19 && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
		return (5);
	if (i + 9 <= 19 && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 9] == '#')
		return (6);
	if (i + 7 <= 19 && str[i + 1] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
		return (7);
	if (i + 10 <= 19 && str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#')
		return (8);
	if (i + 7 <= 19 && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 7] == '#')
		return (9);
	if (i + 10 <= 19 && str[i + 1] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
		return (10);
	return (0);
}

int	 ft_redirect_two(char *str, int i)
{
	if (i + 7 <= 19 && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
		return (11);
	if (i + 11 <= 19 && str[i + 5] == '#' && str[i + 10] == '#' && str[i + 11] == '#')
		return (12);
	if (i + 5 <= 19 && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 5] == '#')
		return (13);
	if (i + 11 <= 19 && str[i + 1] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
		return (14);
	if (i + 5 <= 19 && str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		return (15);
	if (i + 6 <= 19 && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
		return (16);
	if (i + 10 <= 19 && str[i + 4] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
		return (17);
	if (i + 6 <= 19 && str[i + 1] == '#' && str[i + 2] == '#' && str[i + 6] == '#')
		return (18);
	if (i + 10 <= 19 && str[i + 5] == '#' && str[i + 6] == '#' && str[i + 10] == '#')
		return (19);
	return (0);
}