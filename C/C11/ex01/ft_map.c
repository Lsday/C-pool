/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:42:13 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 16:57:09 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*result;

	result = NULL;
	if (length < 1)
		return (result);
	result = malloc(sizeof(int) * length);
	if (result == NULL)
		return (result);
	i = 0;
	while (i < length)
	{
		result[i] = (*f)(tab[i]);
		i++;
	}	
	return (result);
}

// int	test(int n)
// {
// 	return (n * n);
// }

// int main(void)
// {
// 	int tab[] = {1,2,3,4};

// 	int *r = ft_map(tab,4,test); 
// 	return 0;
// }
