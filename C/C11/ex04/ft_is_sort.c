/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:15:07 by oronda            #+#    #+#             */
/*   Updated: 2021/07/27 11:37:00 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	up = 0;
	down = 0;
	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) != 0)
		{
			if ((up == 0) && (down == 0))
			{
				if ((*f)(tab[i], tab[i + 1]) < 0)
					up = 1;
				if ((*f)(tab[i], tab[i + 1]) > 0)
					down = 1;
			}
		}
		if (up && (*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		if (down && (*f)(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}

// int	is_greater_or_less(int a, int b)
// {
// 	return (a - b);
// }

// int main()
// {
// 	int tab[] = {4,3,2,1};
// 	int tab1[] = {1,2,3,4};
// 	int tab2[] = {1,2,4,3};
// 	int tab3[] = {0,0,0,0};
// 	int tab4[] = {0};
// 	int tab5[] = {0, 5};
// 	int r = ft_is_sort(tab,4,is_greater_or_less); 
// 	int r1 = ft_is_sort(tab1,4,is_greater_or_less); 
// 	int r2 = ft_is_sort(tab2,4,is_greater_or_less); 
// 	int r3 = ft_is_sort(tab3,4,is_greater_or_less); 
// 	int r4 = ft_is_sort(tab4,1,is_greater_or_less); 
// 	int r5 = ft_is_sort(tab4,2,is_greater_or_less); 
// 	printf("%d",r);
// 	return 0;
// }
