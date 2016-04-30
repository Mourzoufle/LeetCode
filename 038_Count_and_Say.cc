class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";

		string prev_str = countAndSay(n - 1), cur_str;		// count the numbers of each number occurring in the previous sequence
		char cur_char = prev_str[0], cur_num = 1;			// current number; current occurrence of it
		for (int i = 1; i < prev_str.size(); i++) {
			if (prev_str[i] != cur_char) {					// a different number occurs
				cur_str += to_string(cur_num) + cur_char;
				cur_char = prev_str[i];
				cur_num = 1;
			}
			else
				cur_num++;
		}
		return cur_str + to_string(cur_num) + cur_char;
	}
};