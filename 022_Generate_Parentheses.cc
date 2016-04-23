class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> parentheses;
		if (n > 0)
			get_parentheses("", 0, n, parentheses);

		return parentheses;
	}

private:
	/* find all valid combinations of parentheses given the prefix and max number of left parentheses */
	void get_parentheses(string prefix, int num_left, int max_left, vector<string> &parentheses) {
		if (prefix.size() == max_left * 2) {		// the prefix is already a combination
			parentheses.push_back(prefix);
			return;
		}
		if (num_left < max_left)					// more left parentheses can be added to the prefix
			get_parentheses(prefix + '(', num_left + 1, max_left, parentheses);
		if (num_left > prefix.size() - num_left)	// more right parentheses can be added to the prefix
			get_parentheses(prefix + ')', num_left, max_left, parentheses);
	}
};