/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:43:13 by oronda            #+#    #+#             */
/*   Updated: 2021/07/17 20:06:06 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *src, char *dest);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;

	ptr = malloc(sizeof(*ptr) * (ft_strlen(src) + 1));
	if (!ptr)
		return (0);
	return (ft_strcpy(ptr, src));
}

// int	main()
// {
// 	char str[] = "hello";
// 	char *cpy;

// 	cpy = ft_strdup(str);
// 	return 0;
// }
