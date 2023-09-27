#include "ft.h"

int	ft_is_complete(void)
{
	int	row;
	int	col;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		while (col < GRID_SIZE)
		{
			if (g_rid[row][col] == 0)
			{
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

void	ft_print_grid(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		while (col < GRID_SIZE)
		{
			c = g_rid[row][col] + '0';
			write(1, &c, 1);
			if (col < GRID_SIZE - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	ft_check(int row, int col, int height, int clues[4][GRID_SIZE])
{
	if (ft_is_valid_placement(row, col, height, clues))
	{
		g_rid[row][col] = height;
		if (ft_solve_skyscraper_puzzle(clues))
			return (1);
		g_rid[row][col] = 0;
	}
	return (0);
}

int	ft_solve_skyscraper_puzzle(int clues[4][GRID_SIZE])
{
	int	row;
	int	col;
	int	height;

	row = 0;
	if (ft_is_complete())
		return (1);
	while (row < GRID_SIZE)
	{
		col = 0;
		while (col < GRID_SIZE)
		{
			if (g_rid[row][col] == 0)
			{
				height = 0;
				while (height++ <= GRID_SIZE)
					if (ft_check(row, col, height, clues) == 1)
						return (1);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (0);
}
