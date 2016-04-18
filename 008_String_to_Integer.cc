class Solution {
public:
	int myAtoi(string str) {
		int head = str.find_first_not_of(" ");									// the first character that counts
		if (head == string::npos)												// empty string
			return 0;

		str = str.substr(head, str.find_last_not_of(" ") - head + 1);
		bool is_neg = false;													// flag indicating the number is negative or not
		long res = 0;															// the converted number
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) {
				if (str[i] == '+')
					continue;
				if (str[i] == '-') {
					is_neg = true;
					continue;
				}
			}
			if ((str[i] < '0') || (str[i] > '9'))								// invalid character
				break;
			res = res * 10 + str[i] - '0';
			if (is_neg && (-res < INT_MIN))										// check if the reversed integer is out of range [INT_MIN, INT_MAX]
				return INT_MIN;
			else if (!is_neg && (res > INT_MAX))
				return INT_MAX;
		}
		return is_neg ? -res : res;
	}
};