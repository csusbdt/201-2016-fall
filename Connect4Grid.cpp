#include "Connect4Grid.h"

Connect4Grid::Connect4Grid()
{
	grid = std::vector< std::vector<char> >(6, std::vector<char>(7, ' '));
}

bool Connect4Grid::check_four_in_diagonal(int row1, int col1, int row2, int col2, char disc) const
{
	if (row1 < row2) {
		if (not (row1+3 == row2 and col1+3 == col2)) return false;
		return (grid[row1][col1] == disc and
		grid[row1+1][col1+1] == disc and
		grid[row1+2][col1+2] == disc and
		grid[row1+3][col1+3] == disc);
	}
	if (not (row1-3 == row2 and col1+3 == col2)) return false;
	return (grid[row1][col1] == disc and
	grid[row1-1][col1+1] == disc and
	grid[row1-2][col1+2] == disc and
	grid[row1-3][col1+3] == disc);
}

bool Connect4Grid::check_four_in_horizontal(int row, int col1, int col2, char disc) const
{
	int i;
	for (i = col1; i <= col2; ++i) {
		if (grid[row][i] != disc) return false;
	}
	return true;
}

bool Connect4Grid::check_four_in_vertical(int col, int row1, int row2, char disc) const
{
	int i;
	for (i = row1; i <= row2; ++i) {
		if (grid[i][col] != disc) return false;
	}
	return true;
}

bool Connect4Grid::check_four_in_line(int row1, int col1, int row2, int col2, char disc) const
{
	if (row1 == row2) {
		if (abs(col2 - col1) != 3) return false;
		return check_four_in_horizontal(row1, std::min(col1, col2), std::max(col1, col2), disc);
	} else if (col1 == col2) {
		if (abs(row2 - row1) != 3) return false;
		return check_four_in_vertical(col1, std::min(row1, row2), std::max(row1, row2), disc);
	} else {
		if (col1 < col2) {
			return check_four_in_diagonal(row1, col1, row2, col2, disc);
		} else {
			return check_four_in_diagonal(row2, col2, row1, col1, disc);
		}
	}
}

bool Connect4Grid::drop(int col, char chr)
{
	int i;
	if (grid[0][col] != ' ') return false;
	for (i = 1; i < 6; ++i) {
		if (grid[i][col] != ' ') break;
	}
	grid[i-1][col] = chr;
	return true;	
}

void Connect4Grid::clear()
{
	for (auto& row : grid) {
		for (auto& col : row) {
			col = ' ';
		}
	}
}

void Connect4Grid::draw() const
{
	int i, j;

	std::cout << std::string(4, ' ');
	for (i = 0; i < 7; ++i) {
		std::cout << i << std::string(3, ' ');
	}
	std::cout << std::endl;
	std::cout << "  +---+---+---+---+---+---+---+" << std::endl;
	for (i = 0; i < 6; ++i) {
		std::cout << i << " |";	
		for (j = 0; j < 7; ++j) {
			std::cout << ' ' << grid[i][j] << " |";
		}
		std::cout << std::endl;
		std::cout << "  +---+---+---+---+---+---+---+" << std::endl;
	}
}
