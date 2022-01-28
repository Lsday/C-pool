/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:06:41 by oronda            #+#    #+#             */
/*   Updated: 2021/07/20 09:17:01 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	count;
	long	i;
	int		*tab;

	*range = NULL;
	if (min >= max)
		return (0);
	count = max - min;
	tab = malloc(sizeof(*tab) * count);
	if (!tab)
		return (0);
	i = -1;
	*range = tab;
	while (++i < count)
		tab[i] = min + i;
	return (count);
}

// int main(int argc, char const *argv[])
// {
// 	int *tab;
// 	  int result = ft_ultimate_range(&tab,166,166);
// 	return 0;
// }
