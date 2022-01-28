/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:15:58 by oronda            #+#    #+#             */
/*   Updated: 2021/07/15 19:19:11 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	IsPrime(int nb);

int	ft_find_next_prime(int nb)
{
	if (IsPrime(nb))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}

int	IsPrime(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 1;
	while (i++ && (unsigned long)(i * i) <= (unsigned long)nb)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
