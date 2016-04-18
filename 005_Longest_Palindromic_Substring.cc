class Solution {
public:
	string longestPalindrome(string s) {
		int head, max_length = 0;					// the index of the first character in the longest palindrome substring; the max length
		for (int i = 0; i < s.size(); i++) {
			int cur_length = 1;						// first check the substring centered by s[i]
			while ((i - cur_length >= 0) && (i + cur_length < s.size()) && (s[i - cur_length] == s[i + cur_length]))
				cur_length++;
			if (max_length < cur_length * 2 - 1) {	// longer palindrome substring found
				head = i + 1 - cur_length;
				max_length = cur_length * 2 - 1;
			}
			cur_length = 0;							// then check the substring centered by s[i] and s[i + 1]
			while ((i - cur_length >= 0) && (i + 1 + cur_length < s.size()) && (s[i - cur_length] == s[i + 1 + cur_length]))
				cur_length++;
			if (max_length < cur_length * 2) {		// longer palindrome substring found
				head = i + 1 - cur_length;
				max_length = cur_length * 2;
			}
		}

		return s.substr(head, max_length);
	}
};