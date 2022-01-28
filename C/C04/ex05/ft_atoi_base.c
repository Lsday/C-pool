/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:05:01 by oronda            #+#    #+#             */
/*   Updated: 2021/07/18 14:39:33 by oronda           ###   ########.fr       */
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
			if (str[i] == '+' || str[i] == '-')
				return (0);
			if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ComputeSign( char *str)
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

char	*MoveToNumber(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		str++;
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	i;
	int	signe;

	i = 0;
	nb = 0;
	signe = ComputeSign(str);
	if (!IsValidBase(base))
		return (0);
	str = MoveToNumber(str);
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

// int main(int argc, char const *argv[])
// {
// 	ft_atoi_base("-CrackitoC","Crackito");
// 	return 0;
// }
