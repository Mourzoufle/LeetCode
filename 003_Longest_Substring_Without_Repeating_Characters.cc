class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() < 2)												// empty string or the string has no substring
			return s.size();

		int max_length = 1;
		int idx_head = 0, idx_tail = 0;
		int *char2idx = new int[256];									// mapping each character in the current substring to its index in the string
		for (int i = 0; i < 256; i++)
			char2idx[i] = -1;
		while (true) {
			if ((idx_tail < s.size()) && (char2idx[s[idx_tail]] < 0)) {	// current character is unique
				char2idx[s[idx_tail]] = idx_tail;
				idx_tail++;
			}
			else {
				if (idx_tail - idx_head > max_length)					// longer substring found
					max_length = idx_tail - idx_head;
				if (idx_tail == s.size())								// all characters are checked
					return max_length;
				int idx_head_new = char2idx[s[idx_tail]] + 1;			// characters before the repeated character (the former one) are discarded in the substring
				for (int i = idx_head; i < idx_head_new; i++)
					char2idx[s[i]] = -1;
				idx_head = idx_head_new;
			}
		}
	}
};