class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2)							// need no jump
			return 0;

		int num_step = 1, max_idx = nums[0], head = 1;	// number of jumps; the max index that can be reached; the index of the first element that needs num_step jumps to reach
		while (true) {
			if (max_idx >= nums.size() - 1)				// reach at the last element - find the min number of jumps
				return num_step;
			int cur_max_idx = max_idx;
			num_step++;
			for (int i = head; i <= cur_max_idx; i++)	// for all elements that can be reached in this jump, find the max index that can be reached
				if (i + nums[i] > max_idx)
					max_idx = i + nums[i];
			head = cur_max_idx + 1;
		}
	}
};