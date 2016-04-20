class Solution {
public:
	int romanToInt(string s) {
		int char2num[256];												// mapping each Roman digit to its value
		char2num['M'] = 1000;
		char2num['D'] = 500;
		char2num['C'] = 100;
		char2num['L'] = 50;
		char2num['X'] = 10;
		char2num['V'] = 5;
		char2num['I'] = 1;

		int res = 0;													// the resulting value
		for (int i = 0; i < s.size(); i++) {
			int cur_num = char2num[s[i]];
			if ((i < s.size() - 1) && (cur_num < char2num[s[i + 1]]))	// current Roman digit act as the prefix of the next digit
				res -= cur_num;
			else
				res += cur_num;
		}

		return res;
	}
};