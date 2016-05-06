class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> permutations;
		if (!nums.empty()) {
			sort(nums.begin(), nums.end());				// sort the numbers in increasing order to make it convenient finding duplicated numbers
			get_permutations(nums, 0, permutations);
		}

		return permutations;
	}

private:
	/* get all permutations by recursively determine the number at each index */
	void get_permutations(vector<int> nums, int idx, vector<vector<int>> &permutations) {
		if (nums[idx] == nums.back()) {					// number on this index cannot be replaced - a permutation found
			permutations.push_back(nums);
			return;
		}

		get_permutations(nums, idx + 1, permutations);	// get permutations with the number at this index not changed
		for (int i = idx + 1; i < nums.size(); i++) {	// ...and get all permutations with each possible number at this position
			if (nums[idx] != nums[i]) {
				swap(nums[idx], nums[i]);
				get_permutations(nums, idx + 1, permutations);
			}
		}
	}
};