# 4x4-Skyscraper-Puzzle-Solver

## Project Description
A 4x4 Skyscraper Puzzle Solver implemented in C. Given a set of clues, the program solves the puzzle by placing numbers from 1 to 4 in a 4x4 grid such that each number appears once in each row and column. The program ensures the placement meets the clues, which indicate the number of skyscrapers visible when looking into a row or column.

## Files

- **main.c**: Contains the main function and puzzle initialization.
- **ft.h**: The header file with function declarations and essential definitions.
- **solve.c**: Contains functions for the main puzzle-solving logic.
- **ft_atoi.c**: Provides a custom function for converting a string to an integer.
- **ft_printf.c**: Contains a custom print function.
- **ft_strok.c**: Contains a custom string tokenizer function.

## Usage

1. Compile the source files. gcc *.c - a
2. Run the program with a single argument that contains the clues separated by spaces.
3. If the puzzle can be solved, the program will display the solution.

## Example

For the following clues `input:./a "2 2 1 3 2 2 3 1 1 2 2 4 3 2 1 3"`, the program might output:
`
