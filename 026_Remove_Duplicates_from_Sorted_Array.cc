class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int size = 0;
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] != nums[size])	// current element not equals to the last valid one - make it the new last valid element
				nums[++size] = nums[i];
		return ++size;
	}
};