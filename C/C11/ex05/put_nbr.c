/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:47:54 by oronda            #+#    #+#             */
/*   Updated: 2021/07/26 14:27:19 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	u_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		u_nb = (unsigned int)(nb * -1);
	}
	else
		u_nb = (unsigned int)nb;
	if (u_nb >= 10)
	{
		ft_putnbr(u_nb / 10);
		ft_putchar((u_nb % 10 ) + '0');
	}
	else
		ft_putchar(u_nb + '0');
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}
