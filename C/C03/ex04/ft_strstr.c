/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:09:48 by oronda            #+#    #+#             */
/*   Updated: 2021/07/13 11:34:28 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*to_find))
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j])
			{
				if (to_find[j] == str[i + j])
					j++;
				else
					break ;
				if (to_find[j] == '\0')
					return (str + i);
			}
		}
		i++;
	}
	return (0);
}
