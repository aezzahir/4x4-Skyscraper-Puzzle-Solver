#include "ft.h"

void	ft_print_grid(void);
void	ft_printf(const char *str);
char	*ft_strtok(char *str, const char *delim);

int	ft_print_error(void)
{
	ft_printf("Error\n");
	return (1);
}

void	ft_initialize_grid(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		while (col < GRID_SIZE)
		{
			g_rid[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	parse_input_and_initialize(char *input, int clues[4][GRID_SIZE])
{
	char	*token;
	int		i;
	int		j;

	token = ft_strtok(input, " ");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			if (token == NULL)
				ft_print_error();
			clues[i][j] = ft_atoi(token);
			if (clues[i][j] < 1 || clues[i][j] > 4)
				ft_print_error();
			token = ft_strtok(NULL, " ");
			if (token == NULL && i != 3)
				ft_print_error();
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*input;
	int		clues[4][GRID_SIZE];

	if (argc != 2)
		ft_print_error();
	input = argv[1];
	parse_input_and_initialize(input, clues);
	ft_initialize_grid();
	if (ft_solve_skyscraper_puzzle(clues))
		ft_print_grid();
	return (0);
}
