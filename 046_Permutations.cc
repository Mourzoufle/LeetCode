class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> permutations;
		if (!nums.empty())
			get_permutations(nums, 0, permutations);

		return permutations;
	}

private:
	/* get all permutations by recursively determine the number at each index */
	void get_permutations(vector<int> &nums, int idx, vector<vector<int>> &permutations) {
		if (idx == nums.size() - 1) {						// number on this index cannot be replaced - a permutation found
			permutations.push_back(nums);
			return;
		}
		get_permutations(nums, idx + 1, permutations);		// get permutations with the number at this index not changed
		for (int i = idx + 1; i < nums.size(); i++) {		// ...and get all permutations with each possible number at this position
			swap(nums[idx], nums[i]);
			get_permutations(nums, idx + 1, permutations);
			swap(nums[idx], nums[i]);
		}
	}
};