/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:47:39 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 17:11:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	ft_add(int a, int b)
{
	ft_putnbr (a + b);
	ft_putchar('\n');
}

void	ft_minus(int a, int b)
{
	ft_putnbr (a - b);
	ft_putchar('\n');
}

void	ft_mult(int a, int b)
{
	ft_putnbr (a * b);
	ft_putchar('\n');
}

void	ft_div(int a, int b)
{	
	if (b == 0)
		ft_putstr("Stop : division by zero\n");
	else
	{
		ft_putnbr(a / b);
		ft_putchar('\n');
	}
}

void	ft_mod(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(a % b);
		ft_putchar('\n');
	}
}
