#include"helper.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*is_valid_key(char *str)
{
	int		i;
	int		y;
	char	*result;

	i = 0;
	y = 0;
	while (is_space(*str))
		str++;
	while (*str == '0')
		str++;
	while (is_num(str[i]))
		i++;
	if (i == 0)
	{	
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
	}
	else
	{
		result = malloc(sizeof(char) * i + 1);
		while (y < i)
		{
			result[y] = *str;
			y++;
			str++;
		}	
		result[y] = '\0';
	}

	return(result);
}
