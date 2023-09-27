#include "ft.h"

int	is_delimiter(char c, const char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_token;
	char		*token_start;

	if (str == NULL)
		str = last_token;
	if (str == NULL)
		return (NULL);
	while (*str && is_delimiter(*str, delim))
		str++;
	if (!*str)
		return (last_token = NULL);
	token_start = str;
	while (*str && !is_delimiter(*str, delim))
		str++;
	if (*str)
		*str++ = '\0';
	last_token = str;
	return (token_start);
}
