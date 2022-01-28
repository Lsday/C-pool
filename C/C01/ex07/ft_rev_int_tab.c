/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:47:16 by oronda            #+#    #+#             */
/*   Updated: 2021/07/08 16:59:13 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;

	a = 0;
	b = size - 1;
	while (a < size / 2)
	{
		ft_swap(&tab[a], &tab[b]);
		a++;
		b--;
	}
}
