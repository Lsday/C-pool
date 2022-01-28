/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:41:28 by oronda            #+#    #+#             */
/*   Updated: 2021/07/15 19:44:37 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (nb);
	return (nb * ft_recursive_power(nb, --power));
}

// int main(int argc, char const *argv[])
// {
// 	int i = ft_recursive_power(-2,3);
// 	return 0;
// }