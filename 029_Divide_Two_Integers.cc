class Solution {
public:
	int divide(int dividend, int divisor) {
		if ((divisor == 0) || ((dividend == INT_MIN) && (divisor == -1)))	// OVERFLOW
			return INT_MAX;

		bool is_neg = (dividend < 0) ^ (divisor < 0);						// flag indicating if the resulting quotient is negative
		long dividend_l = labs(dividend), divisor_l = labs(divisor);		// convert the absolute value of dividend and divisor to long to avoid OVERFLOW
		int res = 0;
		while (dividend_l >= divisor_l) {
			int multiplier = 0;
			while (dividend_l >= (divisor_l << ++multiplier));				// find the current max digits divisor can be shifted left while it remains to be no larger than dividend
			res += (1 << --multiplier);
			dividend_l -= (divisor_l << multiplier);
		}
		return is_neg ? -res : res;
	}
};