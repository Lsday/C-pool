/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:13:12 by oronda            #+#    #+#             */
/*   Updated: 2021/07/14 17:12:39 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	 i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	IsValidBase(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

unsigned int	unsignedCast(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		write(1, "-", 1);
		unb = (unsigned int)(nb * -1);
	}
	else
		unb = (unsigned int)nb;
	return (unb);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				finalNb[256];
	int				i;
	int				baselen;
	unsigned int	unbr;

	i = 0;
	if (!IsValidBase(base))
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	baselen = ft_strlen(base);
	unbr = unsignedCast(nbr);
	while (unbr)
	{
		finalNb[i] = (unbr % baselen);
		unbr = unbr / baselen;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[finalNb[i]]);
}
