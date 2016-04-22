class Solution {
public:
	vector<string> letterCombinations(string digits) {
		const string CHARS[] = {				// characters each digit possibly represents
			" ",
			"",
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
		};

		vector<string> strs;					// the resulting strings
		if (!digits.empty())
			get_strs(digits, "", strs, CHARS);

		return strs;
	}

private:
	/* find all possible strings the current digits may represent given the current prefix */
	void get_strs(string digits, string prefix, vector<string> &strs, const string CHARS[]) {
		if (digits.empty()) {					// no more digits for searching, the prefix is one possible string
			strs.push_back(prefix);
			return;
		}

		string chars = CHARS[digits.front() - '0'];
		digits = digits.substr(1);
		for (int i = 0; i < chars.size(); i++)	// for each possible character the first digit may represent, update the prefix and continue to search in the following digits
			get_strs(digits, prefix + chars[i], strs, CHARS);
	}
};