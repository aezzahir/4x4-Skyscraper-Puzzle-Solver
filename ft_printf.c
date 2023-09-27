#include "ft.h"

void	ft_printf(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	write(STDOUT_FILENO, str, length);
}
