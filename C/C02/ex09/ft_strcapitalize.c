/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:25:22 by oronda            #+#    #+#             */
/*   Updated: 2021/07/12 15:30:34 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_number(char *str)
{
	if ((*str >= '0' && *str <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (!ft_str_is_alpha(&str[i - 1]) && !ft_str_is_number(&str[i - 1]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
	}
	return (str);
}
