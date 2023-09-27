#include "ft.h"

int	ft_check_col_up(int row, int col, int height, int clues[4][GRID_SIZE])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	i = 0;
	max_height = 0;
	g_rid[row][col] = height;
	while (i < GRID_SIZE)
	{
		if (g_rid[i][col] > max_height)
		{
			max_height = g_rid[i][col];
			count++;
		}
		i++;
	}
	g_rid[row][col] = 0;
	return (count <= clues[0][col]);
}

int	ft_check_col_down(int row, int col, int height, int clues[4][GRID_SIZE])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = GRID_SIZE - 1;
	g_rid[row][col] = height;
	while (i >= 0)
	{
		if (g_rid[i][col] > max_height)
		{
			max_height = g_rid[i][col];
			count++;
		}
		i--;
	}
	g_rid[row][col] = 0;
	return (count <= clues[1][col]);
}

int	ft_check_row_left(int row, int col, int height, int clues[4][GRID_SIZE])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	g_rid[row][col] = height;
	while (i < GRID_SIZE)
	{
		if (g_rid[row][i] > max_height)
		{
			max_height = g_rid[row][i];
			count++;
		}
		i++;
	}
	g_rid[row][col] = 0;
	return (count <= clues[2][row]);
}

int	ft_check_row_right(int row, int col, int height, int clues[4][GRID_SIZE])
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = GRID_SIZE - 1;
	g_rid[row][col] = height;
	while (i >= 0)
	{
		if (g_rid[row][i] > max_height)
		{
			max_height = g_rid[row][i];
			count++;
		}
		i--;
	}
	g_rid[row][col] = 0;
	return (count <= clues[3][row]);
}

int	ft_is_valid_placement(int row, int col, int height, int clues[4][GRID_SIZE])
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (g_rid[row][i] == height || g_rid[i][col] == height)
		{
			return (0);
		}
		i++;
	}
	if (ft_check_col_up(row, col, height, clues) == 0)
		return (0);
	if (ft_check_col_down(row, col, height, clues) == 0)
		return (0);
	if (ft_check_row_left(row, col, height, clues) == 0)
		return (0);
	if (ft_check_row_right(row, col, height, clues) == 0)
		return (0);
	return (1);
}
