/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:53:34 by oronda            #+#    #+#             */
/*   Updated: 2021/07/15 19:42:52 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power--)
		result = result * nb;
	return (result);
}

// int main(int argc, char const *argv[])
// {
// 	ft_iterative_power(-2,3);
// 	return 0;
// }
