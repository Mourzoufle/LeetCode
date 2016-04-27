class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)								// the permutation is unique
			return;

		int idx = nums.size() - 2;							// index of the element to be changed
		while ((idx >= 0) && (nums[idx] >= nums[idx + 1]))	// find the first element less than the one next to it from the tail of the array
			idx--;
		if (idx >= 0) {										// such an element exists - swap it with the first element larger than it from the tail of the array
			for (int i = nums.size() - 1; i > idx; i--) {
				if (nums[i] > nums[idx]) {
					swap(nums[idx], nums[i]);
					break;
				}
			}
		}
		reverse(nums.begin() + idx + 1, nums.end());		// rearrange the elements following it into nondecreasing order
	}
};