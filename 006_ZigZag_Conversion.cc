class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)																	// no change on the string
			return s;

		string res;																			// the result of zigzag conversion
		for (int i = 0; i < numRows; i++) {
			for (int j = i; j < s.size(); j += 2 * (numRows - 1)) {							// pick one character every numRows * 2 - 1 ones
				res += s[j];
				if ((i > 0) && (i < numRows - 1) && (j + 2 * (numRows - i - 1) < s.size()))	// for rows in the middle, there are two characters picked in each iteration
					res += s[j + 2 * (numRows - i - 1)];
			}
		}
		return res;
	}
};