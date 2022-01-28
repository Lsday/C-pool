#include "helper.h"

t_key	*read_dict(char *path)
{
	int		fd;
	char	buff[BUFFER_SIZE];
	t_key	*keys;
	int		r;
	char	**splited_buffer;

	r = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	r = read(fd, buff, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	splited_buffer = ft_split(buff, "\n");
	keys = create_structs(splited_buffer);
	if (!keys)
		return (NULL);
	return (keys);
}

t_key	*create_structs(char **strs)
{
	t_key	*keys;
	int		i;
	char	**splited_chars;
	int		j;

	splited_chars = NULL;
	i = 0;
	while (strs[i])
		i++;
	keys = malloc(sizeof(t_key) * (i + 1));
	if (!keys)
		return (NULL);
	j = 0;
	while (j < i)
	{
		if (!parse_dict(strs, keys, j, splited_chars))
			return (NULL);
		free(strs[j]);
		free(splited_chars[j]);
		j++;
	}
	keys[j].is_last = 1;
	return (keys);
}

int	parse_dict(char **strs, t_key *keys, int j, char **splited_chars)
{
	char	*value_result;
	int		i;

	i = 0;
	while (strs[j])
		if (strs[j][i++] != ':')
			return (0);
	if (strs[j][0] == ':')
		return (0);
	splited_chars = ft_split_mod(strs[j], ':');
	if (splited_chars == NULL)
		return (0);
	value_result = is_valid_key(splited_chars[0]);
	if (!value_result[0])
		return (0);
	keys[j].value = trim(value_result);
	keys[j].name = trim(splited_chars[1]);
	keys[j].is_last = 0;
	free(value_result);
	return (1);
}

char	*trim(char *str)
{
	int		lenght;
	int		i;
	char	*result;
	int		j;

	lenght = str_len(str);
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[lenght - 1] == ' ')
		lenght--;
	result = malloc(sizeof(char) * (lenght - i) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (i != lenght)
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}
