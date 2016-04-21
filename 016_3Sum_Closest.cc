class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		long sum = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++) {
			sum = twoSumClosest(nums, i, target, sum);
			if (sum == target)
				break;
		}

		return sum;
	}

private:
	/* find the closest sum of three elements containing the one at idx_a, and return the closer one compared to the previous closest sum */
	long twoSumClosest(vector<int>& nums, int idx_a, int target, long sum) {
		long margin = abs(sum - target);			// margin between previous sum and the target
		int head = idx_a + 1, tail = nums.size() - 1;
		while (head < tail) {
			long cur_sum = nums[idx_a] + nums[head] + nums[tail];
			if (abs(cur_sum - target) < margin) {	// closer sum found
				sum = cur_sum;
				if (sum == target)					// no closer one can be found
					break;
				margin = abs(sum - target);
			}
			else if (cur_sum < target)				// b is too small
				while ((head < tail) && (nums[idx_a] + nums[head] + nums[tail] <= target - margin))
					head++;
			else									// c is too large
				while ((tail > head) && (nums[idx_a] + nums[head] + nums[tail] >= target + margin))
					tail--;
		}

		return sum;
	}
};