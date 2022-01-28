/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:57:04 by oronda            #+#    #+#             */
/*   Updated: 2021/07/23 11:29:26 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

void	handle_error(char *arg, char *bin);

#define BUF_SIZE 1

typedef enum e_fildesc
{
	STDIN,
	STDOUT,
	STDERROR
}	t_filedesc;

void	putstr(char *str, t_filedesc fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	display(int fd, t_filedesc std, char *arg, char *bin)
{
	char	buf[BUF_SIZE];
	int		r;

	r = 0;
	r = read(fd, buf, BUF_SIZE);
	if (r == -1)
	{
		handle_error(arg, bin);
		return ;
	}
	write(std, buf, 1);
	while (r > 0 )
	{
		r = read(fd, buf, BUF_SIZE);
		write(std, buf, 1);
	}
}

void	handle_error(char *arg, char *bin)
{
	putstr(basename(bin), STDERROR);
	write(STDERROR, ": ", 2);
	putstr(arg, STDERROR);
	putstr(": ", STDERROR);
	putstr(strerror(errno), STDERROR);
	write(STDERROR, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;

	i = 0;
	if (argc == 1)
	{
		display(STDIN, STDIN, argv[0], argv[0]);
		return (0);
	}
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			handle_error(argv[i], argv[0]);
			continue ;
		}
		display(fd, STDOUT, argv[i], argv[0]);
		close(fd);
	}
	return (0);
}
