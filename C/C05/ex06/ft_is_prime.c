/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:24:09 by oronda            #+#    #+#             */
/*   Updated: 2021/07/15 19:51:07 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
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

// int main(int argc, char const *argv[])
// {
// 	int i = ft_is_prime(7);
// 	return 0;
// }
