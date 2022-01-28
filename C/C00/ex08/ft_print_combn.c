/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:17:32 by oronda            #+#    #+#             */
/*   Updated: 2021/07/08 08:42:51 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	if (n < 0 || n >= 10)
		return ;

		char tab[n];
		int i;

		i = 0;
		while (i != n)
		{
			i++;
			tab[i] = tab[i - 1] + 1; 
		}

		while(i < 10 - n && i > 0)
		{
			while(tab[n-1] != 9)
			{
				tab[n-1]++; 
			}

			

			
		}
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}
