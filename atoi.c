#include "ft.h"

int	ft_atoi(char *s)
{
	int	i;
	int	i_;
	int	num;
	int	j;

	i = 0;
	i_ = 0;
	num = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '-' && j == 0)
			i_++;
		if (*(s + i) >= 48 && *(s + i) <= 57)
		{
			if (i_ % 2 == 0)
				num = num * 10 + (*(s + i) - 48);
			else
				num = num * 10 - (*(s + i) - 48);
			j = i;
		}
		i++;
	}
	return (num);
}
