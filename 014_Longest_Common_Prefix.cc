class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";

		int tail = -1;			// the last index of the common prefix
		while (++tail < strs[0].size()) {
			bool equal = true;	// flag indicating if all the characters of the current index are the same
			for (int i = 0; i < strs.size(); i++) {
				if ((tail == strs[i].size()) || (strs[i][tail] != strs[0][tail])) {
					equal = false;
					break;
				}
			}
			if (!equal)
				break;
		}
		return tail == 0 ? "" : strs[0].substr(0, tail);
	}
};