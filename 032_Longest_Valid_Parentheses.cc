class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;

		int max_size = 0;
		int sizes[s.size()]{0};																				// Dynamic Programming - size of the longest valid parentheses ended with each character
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == ')') {																				// only parentheses ended with ')' are valid
				if (s[i - 1] == '(')																		// a valid pair of parentheses found, the size is sizes[i - 2] + 2
					sizes[i] = i > 1 ? sizes[i - 2] + 2 : 2;
				else if ((i > sizes[i - 1]) && (s[i - 1 - sizes[i - 1]] == '('))							// or the previous characters are nested parentheses, the new size may be sizes[i - 1] + 2
					sizes[i] = sizes[i - 1] + (i > sizes[i - 1] + 1 ? sizes[i - sizes[i - 1] - 2] : 0) + 2;	// need to check if there are more valid parentheses ahead that connect to the current valid ones
				if (sizes[i] > max_size)
					max_size = sizes[i];
			}
		}
		return max_size;
	}
};