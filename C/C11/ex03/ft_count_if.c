/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:51:45 by oronda            #+#    #+#             */
/*   Updated: 2021/07/24 10:10:24 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	count;
	int	i;

	if (length < 1)
		return (0);
	count = 0;
	i = -1;
	while (tab[++i])
	{
		if ((*f)(tab[i]) != 0)
			count++;
	}
	return (count);
}
