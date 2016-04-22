class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> solutions;
		if (nums.size() < 4)
			return solutions;

		sort(nums.begin(), nums.end());
		for (int i = 0; (nums[i] <= (target < 0 ? -1 : target) && (i < nums.size() - 3)); i++) {			// for every possible value of a, find all the groups of three elements whose sum is (target - a)
			threeSum(nums, i, target - nums[i], solutions);
			while ((i < nums.size() - 3) && (nums[i] == nums[i + 1]))										// ignore duplicated value of a
				i++;
		}
		return solutions;
	}

private:
	/* find all the groups of three elements from those after idx_a in the array, whose sum is target */
	void threeSum(vector<int>& nums, int idx_a, long target, vector<vector<int>> &solutions) {
		for (int i = idx_a + 1; (i < nums.size() - 2) && (nums[i] <= (target < 0 ? -1 : target)); i++) {	// for every possible value of b, find all the pairs of two elements whose sum is (target - b)
			twoSum(nums, idx_a, i, target - nums[i], solutions);
			while ((i < nums.size() - 2) && (nums[i] == nums[i + 1]))										// ignore duplicated value of b
				i++;
		}
	}

	/* find all the pairs of two elements from those after idx_b in the array, whose sum is target */
	void twoSum(vector<int>& nums, int idx_a, int idx_b, long target, vector<vector<int>>& solutions) {
		int head = idx_b + 1, tail = nums.size() - 1;														// indices of c and d
		while (head < tail) {
			long sum = nums[head] + nums[tail];
			if (sum > target)																				// d is too large
				while ((tail > head) && (nums[head] + nums[tail] > target))
					tail--;
			else if (sum < target)																			// c is too small
				while ((head < tail) && (nums[head] + nums[tail] < target))
					head++;
			else {																							// find a solution
				vector<int> solution(4);
				solution[0] = nums[idx_a];
				solution[1] = nums[idx_b];
				solution[2] = nums[head];
				solution[3] = nums[tail];
				solutions.push_back(solution);
				while ((head < tail) && (nums[head] + nums[tail] == target))								// ignore duplicated value of c
					head++;
				while ((tail > head) && (nums[head] + nums[tail] > target))
					tail--;
			}
		}
	}
};