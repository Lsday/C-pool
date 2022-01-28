#include "helper.h"

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	dict_error(void)
{
	put_str("Dict Error\n");
	return (0);
}

int	value_error(void)
{
	put_str("Error\n");
	return (0);
}
