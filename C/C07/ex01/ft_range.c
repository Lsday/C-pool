/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:48:49 by oronda            #+#    #+#             */
/*   Updated: 2021/07/22 12:28:57 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	count;
	int	i;

	if (min >= max)
		return (NULL);
	count = max - min;
	tab = malloc(sizeof(*tab) * count);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < count)
		tab[i] = min + i;
	return (tab);
}

///int main()
///{
// 	// int *ptr = ft_range(11,10);
// 	// return 0;
///}