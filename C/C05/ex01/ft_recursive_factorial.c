/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:34:21 by oronda            #+#    #+#             */
/*   Updated: 2021/07/14 20:38:45 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 1)
		return (nb);
	 if (nb == 0)
		return (1);
	 if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
