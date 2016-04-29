class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		bool is_in_rows[9][9] = {false}, is_in_cols[9][9] = {false}, is_in_squares[9][9] = {false};		// flags indicating if each number exists in each row / column / square
		vector<int> indices_empty;																		// indices of the row and column of each empty cells
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					indices_empty.push_back(i);
					indices_empty.push_back(j);
					continue;
				}
				int num = board[i][j] - '1';
				is_in_rows[i][num] = true;
				is_in_cols[j][num] = true;
				is_in_squares[i / 3 * 3 + j / 3][num] = true;
			}
		}
		solveSudoku(board, is_in_rows, is_in_cols, is_in_squares, indices_empty, 0);
	}

private:
	/* solve a Sudoku given the flags, the indices of the empty cells, and the index of the cell that is currently under processing */
	bool solveSudoku(vector<vector<char>>& board, bool is_in_rows[][9], bool is_in_cols[][9], bool is_in_squares[][9], vector<int> &indices_empty, int cur_idx) {
		if (indices_empty.size() == cur_idx)															// no empty cells left - finish
			return true;

		int i = indices_empty[cur_idx], j = indices_empty[cur_idx + 1];									// indices of the row and the column of the current cell
		for (int k = 0; k < 9; k++) {
			if (is_in_rows[i][k] || is_in_cols[j][k] || is_in_squares[i / 3 * 3 + j / 3][k])			// number already exists - try another one
				continue;
			board[i][j] = k + '1';
			is_in_rows[i][k] = true;
			is_in_cols[j][k] = true;
			is_in_squares[i / 3 * 3 + j / 3][k] = true;
			if (solveSudoku(board, is_in_rows, is_in_cols, is_in_squares, indices_empty, cur_idx + 2))	// if the Sudoku can be solved by filling the cell with this number, then finish searching
				return true;
			is_in_rows[i][k] = false;																	// or reset the flags and try another number
			is_in_cols[j][k] = false;
			is_in_squares[i / 3 * 3 + j / 3][k] = false;
		}
		return false;
	}
};