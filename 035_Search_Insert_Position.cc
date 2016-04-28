class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int head = 0, tail = nums.size() - 1;
		while (head < tail) {							// find the first element that is no less than the target
			int mid = (head + tail) / 2;
			if (nums[mid] < target)
				head = mid + 1;
			else
				tail = mid;
		}
		return nums[head] < target ? head + 1 : head;	// even the last element is smaller than the target - insert it to the back of the array
	}
};