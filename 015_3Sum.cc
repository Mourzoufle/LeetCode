class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> solutions;
		if (nums.size() < 3)
			return solutions;

		sort(nums.begin(), nums.end());
		for (int i = 0; (nums[i] <= 0) && (i < nums.size() - 2); i++) { 		// for every possible value of a, find all the pairs of two elements whose sum is -a
			twoSum(nums, i, -nums[i], solutions);
			while ((i < nums.size() - 2) && (nums[i] == nums[i + 1]))			// ignore duplicated value of a
				i++;
		}
		return solutions;
	}

private:
	/* find all the pairs of two elements from those after idx_a in the array, whose sum is target */
	void twoSum(vector<int>& nums, int idx_a, long target, vector<vector<int>>& solutions) {
		int head = idx_a + 1, tail = nums.size() - 1;							// indices of b and c
		while (head < tail) {
			long sum = nums[head] + nums[tail];
			if (sum > target)													// c is too large
				while ((tail > head) && (nums[head] + nums[tail] > target))
					tail--;
			else if (sum < 0)													// b is too small
				while ((head < tail) && (nums[head] + nums[tail] < target))
					head++;
			else {																// find a solution
				vector<int> solution(3);
				solution[0] = nums[idx_a];
				solution[1] = nums[head];
				solution[2] = nums[tail];
				solutions.push_back(solution);
				while ((head < tail) && (nums[head] + nums[tail] == target))	// ignore duplicated value of b
					head++;
				while ((tail > head) && (nums[head] + nums[tail] > target))
					tail--;
			}
		}
	}
};