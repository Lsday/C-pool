/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:00:42 by oronda            #+#    #+#             */
/*   Updated: 2021/07/21 17:32:56 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	j = 0;
	words = 0;
	while (str[i])
	{
		j = 0;
		while (!is_sep(str[i], charset) && str[i])
		{
			if (!j)
				words++;
			i++;
			j++;
		}
		while (is_sep(str[i], charset))
			i++;
	}
	return (words);
}

char	*get_str(char *str, char *charset)
{
	int		i;
	int		count;
	char	*result;

	count = 0;
	i = 0;
	while (!is_sep(str[i], charset) && str[i])
	{
		count ++;
		i++;
	}
	result = malloc(sizeof(char) * count + 1);
	i = 0;
	while (!is_sep(str[i], charset) && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**cut_strs(char *str, char *charset, char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*substr;

	i = 0;
	j = 0;
	k = -1;
	while (str[i])
	{
		j = 0;
		while (!is_sep(str[i], charset) && str[i])
		{
			if (!j)
				substr = get_str(&(str[i]), charset);
			i++;
			j++;
		}
		if (j)
			tab[++k] = substr;
		while (is_sep(str[i], charset))
			i++;
	}
	tab[++k] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs_tab;
	int		words;

	words = count_words(str, charset);
	strs_tab = malloc(sizeof(char *) * words + 1);
	if (!strs_tab)
		return (strs_tab = NULL);
	strs_tab = cut_strs(str, charset, strs_tab);
	return (strs_tab);
}

// int main(int argc, char  *argv[])
// {
// 	char str[]= "arf";
// 	char sep[]= "";
// 	char **result;
//
// 	result = ft_split(str, sep);
// 	int i = -1;
// 	 while (result[++i])
// 	 {		
// 		printf("%s\n", result[i]);
// 	 }
// 	return 0;
// }
