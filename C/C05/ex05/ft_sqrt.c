/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:11:24 by oronda            #+#    #+#             */
/*   Updated: 2021/07/15 16:38:09 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned long	n;

	if (nb < 0)
		return (0);
	n = nb / 2;
	while (n * n > (unsigned long) nb)
		n /= 2;
	while (n * n < (unsigned long) nb)
		n++;
	if (n * n == (unsigned long) nb)
		return (n);
	return (0);
}
