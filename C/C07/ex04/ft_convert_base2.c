/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:58:51 by oronda            #+#    #+#             */
/*   Updated: 2021/07/20 11:43:28 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_unsigned_cast(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		unb = (unsigned int)(nb * -1);
	}
	else
		unb = (unsigned int)nb;
	return (unb);
}

int	ft_check_sign(int nbr)
{
	int	signe;

	signe = 1;
	if (nbr < 0)
		signe = -1;
	return (signe);
}

int	ft_compute_sign( char *str)
{
	int	signe;

	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	return (signe);
}

int	ft_strlen(char *str)
{
	int	 i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_move_to_number(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		str++;
	return (str);
}
