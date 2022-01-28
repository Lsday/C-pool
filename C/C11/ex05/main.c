/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:21:14 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 17:10:51 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	do_op(int a, int b, void(*f)(int, int))
{
	(*f)(a, b);
}

void	create_struct(t_op *s_div)
{
	s_div[0].operator = '+';
	s_div[0].func = &ft_add;
	s_div[1].operator = '-';
	s_div[1].func = &ft_minus;
	s_div[2].operator = '/';
	s_div[2].func = &ft_div;
	s_div[3].operator = '%';
	s_div[3].func = &ft_mod;
	s_div[4].operator = '*';
	s_div[4].func = &ft_mult;
}

t_op_func	get_op(char c, t_op *ops)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (ops[i].operator == c)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}

int	is_valid_op(char *str)
{
	int	i;

	i = 0;
	if (str[i + 1] == '\0' )
		return (1);
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	int			num1;
	int			num2;
	t_op		s_div[5];
	t_op_func	f;

	if (argc != 4 )
		return (0);
	f = NULL;
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (!is_valid_op(argv[2]))
		return (0);
	create_struct(s_div);
	f = get_op(argv[2][0], s_div);
	if (!f)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	do_op(num1, num2, f);
	return (0);
}
