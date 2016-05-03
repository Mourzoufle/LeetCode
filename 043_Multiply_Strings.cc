class Solution {
public:
	string multiply(string num1, string num2) {
		if ((num1 == "0") || (num2 == "0"))					// there is no need to calculate the product
			return "0";

		for (int i = 0; i < num1.size(); i++)
			num1[i] -= '0';
		for (int i = 0; i < num2.size(); i++)
			num2[i] -= '0';
		string res(num1.size() + num2.size(), '\0');		// the product contains at most num1.size() + num2.size() digits
		for (int i = num1.size() - 1; i >= 0; i--) {
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; j--) {
				res[i + j + 1] += num1[i] * num2[j] + carry;
				carry = res[i + j + 1] / 10;
				res[i + j + 1] %= 10;
			}
			res[i] += carry;
		}
		for (int i = 0; i < res.size(); i++)
			res[i] += '0';
		return (res.front() == '0') ? res.substr(1) : res;	// the first digit may be 0 - if so then discard it
	}
};