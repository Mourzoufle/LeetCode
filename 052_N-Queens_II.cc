class Solution {
public:
	int totalNQueens(int n) {
		vector<bool> is_valid_45(2 * n - 1, true), is_valid_90(n, true), is_valid_135(2 * n - 1, true);	// flags indicating if each straight or diagonal line is valid to place a queen
		return get_solutions(n, 0, is_valid_45, is_valid_90, is_valid_135);
	}

private:
	/* recursively find all positions of the queens in and in the front of the current row */
	int get_solutions(int size, int row, vector<bool> &is_valid_45, vector<bool> &is_valid_90, vector<bool> &is_valid_135) {
		if (row == size)																				// all queens are checked and have valid positions - a solution found
			return 1;

		int num_solution = 0;																			// number of solutions with previous queens placed
		for (int i = 0; i < size; i++) {
			if (is_valid_45[row + i] && is_valid_90[i] && is_valid_135[size - 1 + i - row]) {			// lines related to this position are all valid - a candidate position for the current queen
				is_valid_45[row + i] = false;
				is_valid_90[i] = false;
				is_valid_135[size - 1 + i - row] = false;
				num_solution += get_solutions(size, row + 1, is_valid_45, is_valid_90, is_valid_135);
				is_valid_45[row + i] = true;
				is_valid_90[i] = true;
				is_valid_135[size - 1 + i - row] = true;
			}
		}
	}
};