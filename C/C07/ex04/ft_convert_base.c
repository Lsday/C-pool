/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:22:54 by oronda            #+#    #+#             */
/*   Updated: 2021/07/22 12:17:37 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str);
int				ft_compute_sign( char *str);
char			*ft_move_to_number(char *str);
unsigned int	ft_unsigned_cast(int nb);
int				ft_check_sign(int nbr);
char			*ft_create_string(int i, char *base, unsigned int *nb,
					int signe);

char	*ft_putnbr_base(int nbr, char *base)
{
	unsigned int	*result_nb;
	int				i;
	int				baselen;
	unsigned int	unbr;
	char			*result;

	result_nb = malloc(sizeof(unsigned int) * 40);
	i = 0;
	if (nbr == 0)
	{
		result = malloc(sizeof(char) * 2);
		result[0] = base[0];
		result[1] = '\0';
		return (result);
	}
	baselen = ft_strlen(base);
	unbr = ft_unsigned_cast(nbr);
	while (unbr)
	{
		result_nb[i] = (unbr % baselen);
		unbr = unbr / baselen;
		i++;
	}
	return (ft_create_string(i, base, result_nb, ft_check_sign(nbr)));
}

char	*ft_create_string(int wlenght, char *base, unsigned int *nb, int signe)
{
	char	*result;
	int		j;

	if (signe == -1)
	{
		result = malloc((sizeof(char) * wlenght) + 2);
		result[0] = '-';
		j = 1;
		while (--wlenght >= 0)
			result[j++] = (base[nb[wlenght]]);
		result[j] = '\0';
	}	
	else
	{
		j = 0;
		result = malloc((sizeof(char) * wlenght) + 1);
		while (--wlenght >= 0)
			result[j++] = (base[nb[wlenght]]);
		result[j] = '\0';
	}
	return (result);
}

int	ft_is_valid_base(char *str)
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
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	nb;
	unsigned int	i;
	unsigned int	signe;

	i = 0;
	nb = 0;
	signe = ft_compute_sign(str);
	if (!ft_is_valid_base(base))
		return (0);
	str = ft_move_to_number(str);
	while (*str)
	{	
		while (base[i])
		{
			if (*str == base[i])
			{
				nb = nb * ft_strlen(base) + i;
				i = 0;
				break ;
			}
			i++;
		}
		str++;
	}
	return (nb * signe);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*result;

	if (!ft_is_valid_base(base_from))
		return (result = NULL);
	if (!ft_is_valid_base(base_to))
		return (result = NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(nb, base_to));
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str;
// 	str = ft_convert_base("  	-++-2147483647", "0123456789", "0123456789");
// 	printf("%s",str);
// 	return (0);
// }
