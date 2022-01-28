/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:57:12 by oronda            #+#    #+#             */
/*   Updated: 2021/07/11 17:47:59y oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_hex(unsigned char c)
{
	char	*hexDigit;

	hexDigit = "0123456789abcdef";
	write(1, &hexDigit[c / 16], 1);
	write(1, &hexDigit[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			ft_print_hex((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
