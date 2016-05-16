class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;											// the resulting order
		if (matrix.empty() || matrix[0].empty())					// the matrix is empty
			return res;

		int num_row = matrix.size(), num_col = matrix[0].size();	// number of rows and columns
		int num_step = min(num_row, num_col) / 2;
		for (int i = 0; i < num_step; i++) {						// each time scan the elements on the edge until the remain is no longer a matrix
			for (int j = 0; j < num_col - 2 * i - 1; j++)
				res.push_back(matrix[i][i + j]);
			for (int j = 0; j < num_row - 2 * i - 1; j++)
				res.push_back(matrix[i + j][num_col - i - 1]);
			for (int j = num_col - i - 1; j > i; j--)
				res.push_back(matrix[num_row - i - 1][j]);
			for (int j = num_row - i - 1; j > i; j--)
				res.push_back(matrix[j][i]);
		}
		if (num_row < num_col) {
			if (num_row % 2 > 0)									// still one row left
				for (int i = num_step; i < num_col - num_step; i++)
					res.push_back(matrix[num_step][i]);
		}
		else {
			if (num_col % 2 > 0)									// still one column left
				for (int i = num_step; i < num_row - num_step; i++)
					res.push_back(matrix[i][num_step]);
		}

		return res;
	}
};