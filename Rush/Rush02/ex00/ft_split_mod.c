#include "helper.h"

int	is_sep_mod(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

char	*get_substr_mod(char *str, char c)
{
	int		i;
	int		count;
	char	*result;

	count = 0;
	i = 0;
	while (!is_sep_mod(str[i], c) && str[i])
	{
		count++;
		i++;
	}
	result = malloc(sizeof(char) * count + 1);
	i = 0;
	while (!is_sep_mod(str[i], c) && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**cut_strs_mod(char *str, char sep, char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*substr;

	i = 0;
	j = 0;
	k = 0;
	substr = get_substr_mod(str, sep);
	tab[0] = substr;
	while (!is_sep_mod(str[i], sep))
		i++;
	j = i + 1;
	while (str[i])
		i++;
	substr = malloc(sizeof(char) * (i - j) + 1);
	if (!substr)
		return (NULL);
	while (j < i)
		substr[k++] = str[j++];
	substr[k] = '\0';
	tab[1] = substr;
	return (tab);
}

char	**ft_split_mod(char *str, char sep)
{
	char	**strs_tab;

	strs_tab = malloc(sizeof(char *) * 2 + 1);
	if (!strs_tab)
		return (strs_tab = NULL);
	strs_tab = cut_strs_mod(str, sep, strs_tab);
	return (strs_tab);
}
