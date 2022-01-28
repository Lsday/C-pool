/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:04:19 by plaletin          #+#    #+#             */
/*   Updated: 2021/07/10 18:03:54 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_middle(int x, int y, char c);
void	ft_last_line(int x, char c1, char c2, char c3);
void	ft_first_line(int x, char c1, char c2, char c3);

void	ft_first_line(int x, char c1, char c2, char c3)
{
	int	i;

	i = 1;
	ft_putchar(c1);
	while (i <= x - 1)
	{
		if (i < x - 1)
			ft_putchar(c2);
		else if (i == x - 1)
			ft_putchar(c3);
		i++;
	}
	ft_putchar('\n');
	return ;
}

void	ft_middle(int x, int y, char c)
{
	int	x_count;
	int	y_count;

	y_count = 0;
	while (y_count < y - 2)
	{
		x_count = 0;
		ft_putchar(c);
		if (x > 1)
		{
			while (x_count < x - 2)
			{
				ft_putchar(' ');
				x_count++;
			}
			ft_putchar(c);
		}
		ft_putchar('\n');
		y_count++;
	}
}

void	ft_last_line(int x, char c1, char c2, char c3)
{
	int		i;

	i = 0;
	ft_putchar(c1);
	if (x >= 2)
	{
		while (++i < x - 1)
			ft_putchar(c2);
		ft_putchar(c3);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('\n');
		return ;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	ft_first_line(x, 'A', 'B', 'C');
	ft_middle(x, y, 'B');
	if (y > 1)
		ft_last_line(x, 'A', 'B', 'C');
}
