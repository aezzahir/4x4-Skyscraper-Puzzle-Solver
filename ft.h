#ifndef FT_H
# define FT_H

# include <unistd.h>

# define GRID_SIZE 4

int	g_rid[GRID_SIZE][GRID_SIZE];

/* Functions */
int	ft_is_complete(void);
int	ft_check_col_up(int row, int col, int height, int clues[4][GRID_SIZE]);
int	ft_check_col_down(int row, int col, int height, int clues[4][GRID_SIZE]);
int	ft_check_row_left(int row, int col, int height, int clues[4][GRID_SIZE]);
int	ft_check_row_right(int row, int col, int height, int clues[4][GRID_SIZE]);
int	ft_is_valid_placement(int row, int col, int height,
		int clues[4][GRID_SIZE]);
int	ft_solve_skyscraper_puzzle(int clues[4][GRID_SIZE]);
int	ft_atoi(char *s);

#endif
