class Solution {
public:
	bool canJump(vector<int>& nums) {
		int max_idx = 0;						// the max index that can be reached
		for (int i = 0; i <= max_idx; i++) {
			if (i + nums[i] > max_idx)			// further index can be reached
				max_idx = i + nums[i];
			if (max_idx >= nums.size() - 1)		// the last index can be reached
				return true;
		}
		return false;
	}
};