class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> solutions;														// the resulting solutions
		vector<string> solution(n, string(n, '.'));												// current solution
		vector<bool> is_valid_45(2 * n - 1, true), is_valid_90(n, true), is_valid_135(2 * n - 1, true);
		solveNQueens(n, 0, solutions, solution, is_valid_45, is_valid_90, is_valid_135);		// flags indicating if each straight or diagonal line is valid to place a queen

		return solutions;
	}

private:
	/* recursively find all valid positions of the queen in the current row */
	void solveNQueens(int size, int row, vector<vector<string>> &solutions, vector<string> &solution, vector<bool> &is_valid_45, vector<bool> &is_valid_90, vector<bool> &is_valid_135) {
		if (row == size) {																		// all queens are checked and have valid positions - a solution found
			solutions.push_back(solution);
			return;
		}

		for (int i = 0; i < size; i++) {
			if (is_valid_45[row + i] && is_valid_90[i] && is_valid_135[size - 1 + i - row]) {	// lines related to this position are all valid - a candidate position for the current queen
				solution[row][i] = 'Q';
				is_valid_45[row + i] = false;
				is_valid_90[i] = false;
				is_valid_135[size - 1 + i - row] = false;
				solveNQueens(size, row + 1, solutions, solution, is_valid_45, is_valid_90, is_valid_135);
				solution[row][i] = '.';
				is_valid_45[row + i] = true;
				is_valid_90[i] = true;
				is_valid_135[size - 1 + i - row] = true;
			}
		}
	}
};