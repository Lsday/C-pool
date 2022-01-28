/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:34:24 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 11:40:41 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i])
		i++;
	 if (i == 1 || i == 0)
		return ;
	i = 1;
	while (tab[i])
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = temp;
			i = 0;
		}
		i++;
	}
}
