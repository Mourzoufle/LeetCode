class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() > haystack.size())	// the needle is longer than the haystack - impossible to be part of it
			return -1;

		for (int i = 0; i <= haystack.size() - needle.size(); i++) {
			bool equal = true;
			for (int j = 0; j < needle.size(); j++) {
				if (haystack[i + j] != needle[j]) {
					equal = false;
					break;
				}
			}
			if (equal)							// the first occurrence found
				return i;
		}
		return -1;								// found no occurrence
	}
};