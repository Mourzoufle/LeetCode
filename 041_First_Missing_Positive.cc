class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if ((nums[i] <= 0) || (nums[i] > nums.size()) || (nums[i] == nums[nums[i] - 1]))	// for every number in [1, nums.size()], place it to the corresponding index (number - 1)
				continue;
			swap(nums[i], nums[nums[i] - 1]);
			i--;
		}
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1)																// corresponding number not found - missing
				return i + 1;
		return nums.size() + 1;																	// or no number in [1, nums.size()] is missing - return nums.size() + 1
	}
};