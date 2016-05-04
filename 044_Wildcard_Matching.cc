class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();

		bool *match = new bool[s.size() + 1];											// Dynamic Programming - flags indicating if each substring from the first to the current character matches the current pattern
		match[0] = true;																// current pattern and substring are both empty
		for (int i = 1; i <= s.size(); i++)
			match[i] = false;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == '*') {															// any sequence of characters
				for (int j = 0; j < s.size(); j++)
					if (match[j])														// if substring (0, j - 1) matches the previous pattern, then substring (0, j) also matches
						match[j + 1] = true;
			}
			else {																		// a single character
				for (int j = s.size(); j > 0; j--)
					match[j] = match[j - 1] && ((p[i] == '?') || (p[i] == s[j - 1]));	// substring (0, j) matches only when both the substring (0, j - 1) the current character match
				match[0] = false;														// the empty substring no longer matches
			}
		}
		return match[s.size()];
	}
};