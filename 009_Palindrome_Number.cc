class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)									// negative numbers cannot be a palindrome
			return false;
		int origin = x;
		long reversed = 0;							// the reversed number
		while (origin > 0) {
			reversed = reversed * 10 + origin % 10;
			origin /= 10;
			if (reversed > INT_MAX)					// the reversed number is not in the range of int - the number cannot be a palindrome
				return false;
		}
		return reversed == x;
	}
};