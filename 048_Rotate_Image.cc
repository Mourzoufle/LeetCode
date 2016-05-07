class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int max_idx = matrix.size() - 1;								// max index of rows or columns
		for (int i = (max_idx - 1) / 2; i >= 0; i--) {					// each round of swap can process both the current top and bottom rows - only half of the rows needed to be processed
			for (int j = i; j < max_idx - i; j++) {						// process elements in the current top row except for the rightmost one - it belongs to the rightmost column
				swap(matrix[i][j], matrix[j][max_idx - i]);				// current left-top element is placed
				swap(matrix[i][j], matrix[max_idx - i][max_idx - j]);	// current right-top element is placed
				swap(matrix[i][j], matrix[max_idx - j][i]);				// current bottom elements are placed
			}
		}
	}
};