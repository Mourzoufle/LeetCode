class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool is_in_rows[9][9] = {false}, is_in_cols[9][9] = {false}, is_in_squares[9][9] = {false};		// flags indicating if each number exists in each row / column / square

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')																	// an empty posistion
					continue;
				int num = board[i][j] - '1';
				if (is_in_rows[i][num] || is_in_cols[j][num] || is_in_squares[i / 3 * 3 + j / 3][num])	// same number already exists in the corresponding row / column / square - invalid
					return false;
				is_in_rows[i][num] = true;
				is_in_cols[j][num] = true;
				is_in_squares[i / 3 * 3 + j / 3][num] = true;
			}
		}
		return true;
	}
};