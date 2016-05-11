class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> solutions;																																	// the resulting solutions
		vector<string> solution(n, string(n, '.'));																															// current solution
		solveNQueens(0, solutions, solution);

		return solutions;
	}

private:
	/* recursively find all valid positions of the queen in the current row */
	void solveNQueens(int row, vector<vector<string>> &solutions, vector<string> &solution) {
		int size = solution.size();
		if (row == size) {																																					// all queens are checked and have valid positions - a solution found
			solutions.push_back(solution);
			return;
		}

		for (int i = 0; i < size; i++) {
			bool is_valid = true;																																			// flag indicating if the current column is valid
			for (int j = 0; j < row; j++) {
				if ((solution[j][i] == 'Q') || ((i + row - j < size) && (solution[j][i + row - j] == 'Q')) || ((i + j - row >= 0) && (solution[j][i + j - row] == 'Q'))) {
					is_valid = false;
					break;
				}
			}
			if (is_valid) {
				solution[row][i] = 'Q';
				solveNQueens(row + 1, solutions, solution);
				solution[row][i] = '.';
			}
		}
	}
};