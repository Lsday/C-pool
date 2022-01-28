/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:33:55 by oronda            #+#    #+#             */
/*   Updated: 2021/07/19 16:51:48 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		total_len;

	total_len = 0;
	if (size == 0)
	{
		result = malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	i = -1;
	while (++i < size)
		total_len += ft_strlen(strs[i]);
	total_len += ft_strlen(sep) * (size - 1) + 1;
	result = malloc(total_len);
	*result = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
	}
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	char *result;
// 	result = ft_strjoin(2,argv,"||");
// 	printf("%s", result);
// 	return 0;
// }