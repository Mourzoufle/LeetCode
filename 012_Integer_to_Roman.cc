class Solution {
public:
	string intToRoman(int num) {
		const int NUM_VALUE = 13;				// number of different Roman digits and their corresponding value
		const int VALUES[NUM_VALUE] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string ROMANS[NUM_VALUE] = {
			"M",
			"CM",
			"D",
			"CD",
			"C",
			"XC",
			"L",
			"XL",
			"X",
			"IX",
			"V",
			"IV",
			"I"
		};

		string res;								// the resulting Roman numeral
		for (int i = 0; i < NUM_VALUE; i++) {
			if (num >= VALUES[i]) {				// this Roman digit will be used
				for (int j = num / VALUES[i]; j > 0; j--)
					res += ROMANS[i];
				num %= VALUES[i];				// then continue to process the residue
			}
			if (num == 0)						// no more digits left
				break;
		}

		return res;
	}
};