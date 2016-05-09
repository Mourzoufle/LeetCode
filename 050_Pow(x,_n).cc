class Solution {
public:
	double myPow(double x, int n) {
		if ((x == 1) || (n == 0))		// the result is 1
			return 1;
		if (x == -1)					// the result depends on n is odd or even
			return n % 2 == 0 ? 1 : -1;
		if (n == INT_MIN)				// calculate the result in normal mode will cause OVERFLOW
			return abs(x) < 1 ? INT_MAX : 0;

		if (n < 0) {					// keep n positive
			x = 1 / x;
			n = -n;
		}
		double res = 1;					// the result
		while (n > 0) {
			int cur_expon = 2;			// current exponent (*2) - max power of 2 in range [2, n]
			double cur_res = x;			// result under the current exponent
			while (cur_expon <= n) {
				cur_res *= cur_res;
				if (cur_res == 0)		// x < 1 and n is too large to make x^n = 0
					return 0;
				cur_expon <<= 1;
			}
			res *= cur_res;
			n -= cur_expon >> 1;
		}
		return res;
	}
};