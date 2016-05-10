class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> solutions;																// the resulting solutions

		int *cols = new int[n];																			// the index of the column that the queen in each row posits
		for (int i = 0; i < n; i++)
			cols[i] = -1;
		int cur_idx = 0;																				// index of the row that the current queen posits
		while (cur_idx >= 0) {																			// cur_idx < 0 indicates all possible positions of the queens are searched - no more solutions
			while (++cols[cur_idx] < n) {																// loop until there is no possible column the current queen can posits
				bool is_valid = true;																	// flag indicating if the position is valid
				for (int i = 0; i < cur_idx; i++) {
					if (cols[i] == cols[cur_idx] || (abs(cols[cur_idx] - cols[i]) == cur_idx - i)) {	// conflict occurs between two queens
						is_valid = false;
						break;
					}
				}
				if (is_valid)
					break;
			}
			if (cols[cur_idx] == n)																		// no valid position of the current queen can be found - change the position of the former queen
				cols[cur_idx--] = -1;
			else {
				if (cur_idx == n - 1) {																	// all queens are placed well - a solution found
					vector<string> solution;
					for (int i = 0; i < n; i++) {
						string row;
						for (int j = 0; j < n; j++)
							row += (j == cols[i] ? 'Q' : '.');
						solution.push_back(row);
					}
					solutions.push_back(solution);
					cols[cur_idx--] = -1;
				}
				else																					// ...or more queens need to be placed
					cur_idx++;
			}
		}
		return solutions;
	}
};