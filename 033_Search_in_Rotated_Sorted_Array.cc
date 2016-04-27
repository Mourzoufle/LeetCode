class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;

		int head = 0, tail = nums.size() - 1;
		while (head < tail) {				// find the index of the smallest number
			int mid = (head + tail) / 2;
			if (nums[mid] > nums[tail])
				head = mid + 1;
			else
				tail = mid;
		}
		if (target < nums[head])			// target is even smaller than the smallest number - not found
			return -1;
		if (target <= nums.back())			// target in the range from the smallest number to the last one - find in the latter half
			tail = nums.size() - 1;
		else								// or find target in the former half
			head = 0;
		while (head < tail) {
			int mid = (head + tail) / 2;
			if (nums[mid] < target)
				head = mid + 1;
			else if (nums[mid] > target)
				tail = mid - 1;
			else
				return mid;
		}
		return nums[head] == target ? head : -1;
	}
};