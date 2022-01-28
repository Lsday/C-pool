/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:40:34 by oronda            #+#    #+#             */
/*   Updated: 2021/07/10 10:57:41 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		unb = (unsigned int)(-1 * nb);
		ft_putchar('-');
	}
	else
		unb = (unsigned int)nb;
	if (unb >= 10)
	{
		ft_putnbr(unb / 10);
		ft_putchar((unb % 10) + '0');
	}
	else
		ft_putchar(unb + '0');
}
