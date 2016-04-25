class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
			if (nums[i] == val)	// value of current element equals to the one to be removed - swap it with the last one and update the size of array
				nums[i--] = nums[--size];

		return size;
	}
};