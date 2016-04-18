class Solution {
public:
	int reverse(int x) {
		bool is_neg = x < 0;				// flag indicating the number is negative or not
		x = abs(x);
		long res = 0;						// the reversed integer
		while (x > 0) {
			res = res * 10 + x % 10;
			x /= 10;
			if (is_neg && -res < INT_MIN)	// check if the reversed integer is out of range [INT_MIN, INT_MAX]
				return 0;
			else if (!is_neg && res > INT_MAX)
				return 0;
		}

		return is_neg ? -res : res;
	}
};