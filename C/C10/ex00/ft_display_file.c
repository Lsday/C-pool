/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:58:17 by oronda            #+#    #+#             */
/*   Updated: 2021/07/23 11:12:17 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1

void	putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
}

void	display(int fd, char *buf)
{
	int		r;

	r = 0;
	r = read(fd, buf, BUF_SIZE);
	write(1, buf, 1);
	while (r > 0 )
	{
		r = read(fd, buf, BUF_SIZE);
		write(1, buf, 1);
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	buf[BUF_SIZE];

	if (argc == 1)
	{
		putstr_error("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		putstr_error("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		putstr_error("Cannot read file.\n");
		return (1);
	}
	display(fd, buf);
	close(fd);
	return (0);
}
