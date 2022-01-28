#include "helper.h"

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_key(char *value, t_key *keys)
{
	int	i;

	i = -1;
	while (keys[++i].value != NULL)
	{
		if (ft_strcmp(value, keys[i].value) == 0)
		{
			ft_putstr(keys[i].name);
			break ;
		}
	}
}

int	find_key(char *value, t_key *keys)
{
	int	i;

	i = -1;
	while (keys[++i].value != NULL)
	{
		if (ft_strcmp(value, keys[i].value) == 0)
			return (1);
	}
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*check_valid_nbr(char *str)
{
	int	i;

	while (*str == '0')
		str++;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		i++;
	}
	return (str);
}	

void	set_trios_to_minus_one(t_trio *trios, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		trios[i].unit = 0;
		trios[i].dozen = 0;
		trios[i].hundred = 0;
		i++;
	}
	trios[i].unit = -1;
	trios[i].dozen = -1;
	trios[i].hundred = -1;
}

void	print_trio2(t_trio trio, t_key *keys, int last)
{
	char	dozen[3];

	if (trio.dozen != -1 && trio.dozen != 0 && trio.dozen != 1)
	{
		dozen[0] = trio.dozen + 48;
		dozen[1] = '0';
		dozen[2] = '\0';
		print_key(dozen, keys);
		if (last != 0 || trio.unit != 0)
			write(1, "-", 1);
	}
	print_trio3(trio, keys, last);
}

void	print_trio3(t_trio trio, t_key *keys, int last)
{
	char	dozen[3];
	char	unit[2];

	if (trio.dozen == 1)
	{
		dozen[0] = '1';
		dozen[1] = trio.unit + 48;
		dozen[2] = '\0';
		print_key(dozen, keys);
		if (last != 1)
			write(1, " ", 1);
	}
	else if (trio.unit != 0)
	{
		unit[0] = trio.unit + 48;
		unit[1] = '\0';
		print_key(unit, keys);
		if (last != 1)
			write(1, " ", 1);
	}
}

void	print_trio(t_trio trio, t_key *keys, int last)
{
	int		i;
	char	unit[2];

	i = 0;
	if (trio.hundred != -1 && trio.hundred != 0)
	{
		unit[0] = trio.hundred + 48;
		unit[1] = '\0';
		print_key(unit, keys);
		write(1, " ", 1);
		print_key("100", keys);
	}
	if ((trio.dozen != 0 || trio.unit != 0) && trio.hundred != 0)
		write(1, " and ", 5);
	else if ((last == 0 || trio.dozen != 0 || trio.unit != 0) && trio.hundred != 0)
		write(1, " ", 1);
	print_trio2(trio, keys, last);
}	

void	set_trios_value(char *nbr, t_trio *trios, int trios_size, int size)
{
	int	i;
	int	j;

	i = size;
	j = 0;
	while (--i >= 0)
	{
		if (j % 3 == 0)
			trios[trios_size - 2].unit = nbr[i] - 48;
		else if (j % 3 == 1)
			trios[trios_size - 2].dozen = nbr[i] - 48;
		else if (j % 3 == 2)
		{
			trios[trios_size - 2].hundred = nbr[i] - 48;
			trios_size--;
		}
		j++;
	}
}

t_trio	*read_number(char *nbr)
{
	t_trio	*trios;
	int		size;
	int		trios_size;

	nbr = check_valid_nbr(nbr);
	if (nbr == NULL)
		return (NULL);
	size = str_len(nbr);
	trios_size = (size - 1) / 3 + 2;
	trios = malloc(sizeof(t_trio) * trios_size);
	if (trios == NULL)
		return (NULL);
	set_trios_to_minus_one(trios, trios_size);
	set_trios_value(nbr, trios, trios_size, size);
	return (trios);
}

char	*value_generator(int n)
{
	char	*value;
	int		i;

	value = malloc(sizeof(char) * (n + 2));
	value[0] = '1';
	i = 0;
	while (++i < n + 1) 
		value[i] = '0';
	value[i] = '\0'; 
	return (value);
}

void	print_nbr(t_trio *trios, t_key *keys)
{
	int		i;
	int		size;
	char	*value;
	int		last;

	last = 0;
	size = 0;
	while (trios[size].unit != -1)
		size++;
	i = 0;
	while (trios[i].unit != -1)
	{
		if (!(trios[i].unit == 0 && trios[i].dozen == 0 &&
				trios[i].hundred == 0))
		{
			if (i == size -1)
				last = 1;
			print_trio(trios[i], keys, last);
			if (size - 1 - i > 0)
			{
				value = value_generator((size - 1 - i) * 3);
				print_key(value, keys);
				if (i <= size - 2)
				{
					write(1, ", ", 2);
				}
			}
			if (size - 1 - i > 0)
				free(value);
		}
		else if (i == size - 1 && size == 1)
		{
			print_key("0", keys);
		}
		i++;
	}
}

int	max_printable(t_key *keys)
{
	int		i;
	char	*value;

	i = 12 * 3;
	while (1)	
	{
		value = value_generator(i);
		if (!(find_key(value, keys)))
		{
			free(value);
			return (i);
		}
		free(value);
		i += 3;
	}
}

int	check_max_printable(int ac, char **av, t_key *keys, char *user_input)
{
	if (ac == 2)
	{
		while (*av[1] == '0')
			av[1]++;
		if (max_printable(keys) < str_len(av[1]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (ac == 3)
	{
		while (*av[1] == '0')
			av[2]++;
		if (max_printable(keys) < str_len(av[2]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (ac == 1)
	{
		while (user_input[0] == '0')
			av[1]++;
		if (max_printable(keys) < str_len(user_input))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	keys_error(t_key *keys, t_trio *trios)
{
	int	i;

	i = -1;
	while (keys[++i].is_last != 1)
	{
		free(keys[i].value);
		free(keys[i].name);
	}	
	i = -1;
	free(trios);
	write(1, "Dict Error\n", 11);
	return (0);
}

void	free_struct(t_key *keys, t_trio *trios)
{
	int	i;

	i = -1;
	while (keys[++i].is_last != 1)
	{
		free(keys[i].value);
		free(keys[i].name);
	}	
	i = -1;
	free(trios);
}

int	check_doublon_key(t_key *keys)
{
	int	i;
	int	j;

	i = 0;
	while (keys[i].is_last == 0)
	{
		j = 0;
		while (keys[j].is_last == 0)
		{
			if (ft_strcmp(keys[j].value, keys[i].value) == 0 && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	std_in()
{
	t_key	*keys;
	t_trio	*trios;
	char	b[32000];

	while (1)
	{
		read(0, b, 32000);
		printf("strlen = %d\n", str_len(b));
		b[str_len(b) - 1] = '\0'; 
		trios = read_number(b);
		if (trios == NULL)
			return (value_error());
		keys = read_dict("numbers.dict");
		if (keys == NULL || check_doublon_key(keys) == 0)
			return (keys_error(keys, trios));
		if(check_max_printable(1, 0, keys, b) == 0)
		{
			free_struct(keys, trios);
			return (value_error());
		}
		print_nbr(trios, keys);	
		write(1, "\n", 1);
		free_struct(keys, trios);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_key	*keys;
	t_trio	*trios;

	if (ac > 3)
		return (0);
	if (ac == 1)
		return(std_in());
	trios = read_number(av[ac - 1]);
	if (trios == NULL)
		return (value_error());
	if (ac == 2)
		keys = read_dict("numbers.dict");
	if (ac == 3)
		keys = read_dict(av[1]);
	if (keys == NULL || check_doublon_key(keys) == 0)
		return (keys_error(keys, trios));
	if(check_max_printable(ac, av, keys, "") == 0)
	{
		free_struct(keys, trios);
		return (0);	
	}
	print_nbr(trios, keys);	
	write(1, "\n", 1);
	free_struct(keys, trios);
	return (0);
}