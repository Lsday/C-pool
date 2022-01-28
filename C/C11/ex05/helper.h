/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 10:27:43 by oronda            #+#    #+#             */
/*   Updated: 2021/07/26 14:26:37 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <unistd.h>
# include <stdlib.h>

typedef void	(*t_op_func)(int, int);

typedef struct s_op
{
	char	operator;
	void	(*func)(int, int);
}	t_op;

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_add(int a, int b);
void	ft_minus(int a, int b);
void	ft_mult(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif