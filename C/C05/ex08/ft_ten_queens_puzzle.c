/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:06:22 by oronda            #+#    #+#             */
/*   Updated: 2021/07/29 10:36:13 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<unistd.h>
#include<stdio.h>

// void printmap(int board[10][10])
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	char pouet;

// 	while(j < 10)
// 	{
// 		i = 0;
// 		while (i < 10)
// 		{
// 			pouet = board[i][j] + '0';
// 			write(1, &pouet, 1);
// 			i++;
// 		}
// 		j++;
// 		write(1,"\n",1);
// 	}
// 	write(1,"\n",1);
// }

void printmap(int result[10])
{
	int i;
	int print;	

	while(i < 10)
	{	
		print = result[i] + '0';
		write(1,&print,1);
		i++;
	}
		
}

int	is_valid(int board[10][10], int x, int y)
{	
	int i;
	int j;

	i = x;
	j = y;
	while (i >= 0)
		if (board[i--][y] == 1) // horizontal check
			return (0);
	i = x;
	j = y;
	while (j >= 0 && i >= 0)
		if (board[i--][j--] == 1) // upper left diagonal
			return (0);
	i = x;
	j = y;
	while ( i >= 0 && j <= 10 )
		if (board[i--][j++] == 1) // down left diagonal
			return (0);
	return (1);
}

void init(int board[10][10])
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while(y < 10)
	{
		x = 0;
		while (x < 10)
		{
			board[x][y] = 0;
			x++;
		}
		y++;
	}
}

void	place_queen(int board[10][10], int x, int y , int result[10])
{
	if (x >= 10)
	{
		printmap(result);
		return;
	}
	y = 0;
		//printmap(board);
	while( y < 10)
	{
		if (x < 10 && y < 10)
		{
			if (is_valid(board, x, y))
			{
				board[x][y] = 1;
				place_queen(board, x + 1, y, result);
				board[x][y] = 0;
				result[x] = y;
				
			}
		}
		y++;
	}
	
	

	
}

 int ft_ten_queens_puzzle(void)
 {
	int	board[10][10];
	int	row;
	int x;
	int y;
	int result [10];

	row = 0;
	x = 0;
	y = 0;
	init(board);
	place_queen(board, x, y, result);
	
	return 0;
}
 
int	main(int argc, char *argv[])
{	
	int result;
	result = ft_ten_queens_puzzle();
	return (0);
}


