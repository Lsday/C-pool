#ifndef HELPER_H
# define HELPER_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 512000

typedef struct s_trio
{
	short	hundred;
	short	dozen;
	short	unit;
}	t_trio;

typedef struct s_key
{
	char	*name;
	char	*value;
	int		is_last;
}	t_key;

int		ft_atoi(char *str);
void	print_trio(t_trio trio, t_key *keys, int last);
void	print_trio2(t_trio trio, t_key *keys, int last);
void	print_trio3(t_trio trio, t_key *keys, int last);
void	print_nb(t_trio *trios);
int		find_key(char *nbr, t_key *keys);
char	*trim(char *str);
t_key	*read_dict(char *path);
void	print_key(char *value, t_key *keys);
char	**ft_split(char *str, char *charset);
char	**ft_split_mod(char *str, char sep);
int		str_len(char *str);
t_key	*create_structs(char **strs);
int		dict_error(void);
int		value_error(void);
int		parse_dict(char **strs, t_key *keys, int j, char **splited_chars);
char	*is_valid_key(char *str);

#endif