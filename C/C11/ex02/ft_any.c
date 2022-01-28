/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:46:27 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 10:10:29 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	while (tab[++i])
	{
		result = (*f)(tab[i]);
		if (result != 0)
			return (1);
	}
	return (0);
}

// int is_str_alpha(char *str)
// {
// 	int i;
// 	i = -1;
// 	while(str[++i])
// 	{
// 		if(!(str[i] >= 'A' && str[i] <= 'Z'))
// 			return (0);
// 	}
// 	return(1);
// }

// int main(int argc, char *argv[])
// {
// 	int r = ft_any(argv, &is_str_alpha);
// 	printf("%d", r);
// 	return 0;
// }
