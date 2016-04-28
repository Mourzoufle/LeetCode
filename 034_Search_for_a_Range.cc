class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> indices(2);		// the resulting indices
		indices[0] = -1;
		indices[1] = -1;
		int head = 0, tail = nums.size() - 1;
		while (head < tail) {		// find the first element that is not less than the target
			int mid = (head + tail) / 2;
			if (nums[mid] < target)
				head = mid + 1;
			else
				tail = mid;
		}
		if (nums[head] != target)	// target not found
			return indices;
		indices[0] = head;
		tail = nums.size() - 1;
		while (head < tail) {		// find the last element that equals to the target
			int mid = (head + tail + 1) / 2;
			if (nums[mid] > target)
				tail = mid - 1;
			else
				head = mid;
		}
		indices[1] = head;
		return indices;
	}
};