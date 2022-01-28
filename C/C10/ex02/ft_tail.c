/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:01:23 by oronda            #+#    #+#             */
/*   Updated: 2021/07/22 19:02:09 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void	handle_error(char *arg);

#define BUF_SIZE 1

typedef enum e_fildesc
{
	STDIN,
	STDOUT,
	STDERROR
}	t_filedesc;

void	putstr(char *str, t_filedesc std)
{
	int	i;

	i = 0;
	while (str[i])
		write(std, &str[i++], 1);
}

void	display(int fd, t_filedesc std, char *arg)
{
	char	buf[BUF_SIZE + 1];
	int		r;

	r = 0;
	r = read(fd, buf, BUF_SIZE);
	if (r == -1)
	{
		handle_error(arg);
		return ;
	}
	buf[r] = '\0';
	putstr(buf, std);
	while (r > 0 )
	{
		r = read(fd, buf, BUF_SIZE);
		buf[r] = '\0';
		putstr(buf, std);
	}
	buf[r] = '\0';
}

void	display_tail(int fd, char *arg, int count, int tail)
{
	char	buf[BUF_SIZE + 1];
	int		r;
	int i;

	i = 0;
	r = 0;
	r = read(fd, buf, BUF_SIZE);
	i += r;
	if (r == -1)
	{
		handle_error(arg);
		return ;
	}
	buf[r] = '\0';
	putstr(buf, 1);
	while (r > 0 && i < (count - tail) )
	{
		r = read(fd, buf, BUF_SIZE);
		i += r;
	}

	while (r > 0 )
	{
		r = read(fd, buf, BUF_SIZE);
		buf[r] = '\0';
		putstr(buf, 1);
	}
	
	buf[r] = '\0';
}

int	ft_count(int fd, char *arg)
{
	char	buf[BUF_SIZE];
	int		r;
	int		count;

	count = 0;
	r = 0;
	r = read(fd, buf, BUF_SIZE);
	count += r;
	if (r == -1)
	{
		handle_error(arg);
		return (0);
	}
	while (r > 0 )
	{
		r = read(fd, buf, BUF_SIZE);
		count += r;
	}
	close(fd);
	return (count);
}

void	handle_error(char *arg)
{
	putstr("tail: ", STDERROR);
	putstr(arg, STDERROR);
	putstr(": ", STDERROR);
	putstr(strerror(errno), STDERROR);
	write(STDERROR, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	signe;

	nb = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = 10 * nb + (*str - '0');
		str++;
	}
	return (nb * signe);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int bcount;

	i = 0;
	if (argc == 1)
	{
		display(STDIN, STDIN, argv[0]);
		return (0);
	}

	if (argc >= 3)
	{
		while (argv[1])
		{
			if (!ft_strcmp("-c",argv[1]))
				return (1);
		}
		
		
	}
	
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		bcount = ft_count(fd,argv[i]);
		if (bcount == 0)
		{
			return 1;
		}
		
		if (fd < 0)
		{
			handle_error(argv[i]);
			continue ;
		}
		fd = open(argv[i], O_RDONLY);
		display_tail(fd, argv[i], bcount, 10);
		close(fd);
	}
	return (0);
}
