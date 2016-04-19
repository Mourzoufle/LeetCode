class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();

		bool *match = new bool[s.size() + 1];										// Dynamic Programming - flags indicating if each substring from the first to the current character matches the current pattern
		match[0] = true;															// current pattern and substring are both empty
		for (int i = 1; i <= s.size(); i++)
			match[i] = false;
		for (int i = 0; i < p.size(); i++) {
			if ((i < p.size() - 1) && (p[i + 1] == '*')) {							// a repeated character
				for (int j = 0; j < s.size(); j++)
					if (match[j] && ((p[i] == '.') || (p[i] == s[j])))				// if substring (0, j - 1) matches the previous pattern and the current character also matches, then substring (0, j) matches
						match[j + 1] = true;										// ...or the matching status of substring (0, j) do not change
				i++;
			}
			else {
				bool has_match = false;												// flag indicating if there is a matched substring to the current pattern
				for (int j = s.size() - 1; j >= 0; j--) {
					match[j + 1] = match[j] && ((p[i] == '.') || (p[i] == s[j]));	// substring (0, j) matches only when both the substring (0, j - 1) the current character match
					if (match[j + 1])
						has_match = true;
				}
				match[0] = false;													// the empty substring no longer matches
				if (!has_match)
					return false;
			}
		}
		return match[s.size()];
	}
};