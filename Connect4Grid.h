#ifndef CONNECT4GRID_H
#define CONNECT4GRID_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

class Connect4Grid {
private:
	std::vector< std::vector<char> > grid;	
	bool check_four_in_horizontal(int row, int col1, int col2, char disc) const;
	bool check_four_in_vertical(int col, int row1, int row2, char disc) const;
	bool check_four_in_diagonal(int row1, int col1, int row2, int col2, char disc) const;
public:
	Connect4Grid();

	/* Returns true if the line formed from coordinates (row1, column1) and (row2, column2)
	 * are all cells containing disc as a character value
	 */
	bool check_four_in_line(int row1, int column1, int row2, int column2, char disc) const;

	/* Drops disc with a labeled character value into the column specified by column.
	 * Returns false if the column is full
	 */
	bool drop(int column, char disc);

	/* Clears the grid */
	void clear();

	/* Displays the grid in the terminal window */
	void draw() const;
};

#endif
