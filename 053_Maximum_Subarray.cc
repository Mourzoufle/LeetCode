class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max_sum = nums[0], cur_sum = max(nums[0], 0);	// the max sum over the array; the max sum of elements including the current one
		for (int i = 1; i < nums.size(); i++) {
			cur_sum += nums[i];
			if (cur_sum > max_sum)							// new max sum found
				max_sum = cur_sum;
			if (cur_sum < 0)								// discard the current sum since it will only reduce the sum of the following elements
				cur_sum = 0;
		}

		return max_sum;
	}
};