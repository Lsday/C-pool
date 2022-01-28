/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:32:51 by oronda            #+#    #+#             */
/*   Updated: 2021/07/08 17:01:46 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 1;
	while (i <= size - 1)
	{
		if (tab[i - 1] > tab[i])
		{
			ft_swap(&tab[i], &tab[i - 1]);
			i = 0;
		}
		i++;
	}
}
