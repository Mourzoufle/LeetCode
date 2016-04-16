class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> indices;    			// the final result - empty if there is no solution
		map<int, int> num2idx;				// mapping each different number to its index in the vector
		for (int i = 0; i < nums.size(); i++)
			num2idx[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++) {
			int diff = target - nums[i];	// if diff exists in the vector, then the solution is found
			if ((num2idx.find(diff) != num2idx.end()) && (num2idx[diff] != i)) {
				indices.push_back(i);
				indices.push_back(num2idx[diff]);
				break;
			}
		}

		return indices;
	}
};