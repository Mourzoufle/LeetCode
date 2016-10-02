class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() < 2)											// empty string or the string has no substring
			return s.size();

		int max_length = 1;
		int head = 0, tail = 0;
		int *char2idx = new int[256];								// mapping each character in the current substring to its index in the string
		for (int i = 0; i < 256; i++)
			char2idx[i] = -1;
		while (true) {
			while ((tail < s.size()) && (char2idx[s[tail]] < 0)) {	// current character is unique
				char2idx[s[tail]] = tail;
				tail++;
			}
			max_length = max(max_length, tail - head);				// update the max length
			if (tail == s.size())									// all characters are checked
				return max_length;
			int head_new = char2idx[s[tail]] + 1;					// characters before the repeated character (the former one) are discarded in the substring
			while (head < head_new)
				char2idx[s[head++]] = -1;
		}
	}
};
