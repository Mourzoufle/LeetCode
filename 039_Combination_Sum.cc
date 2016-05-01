class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> combinations;																// valid combinations
		sort(candidates.begin(), candidates.end());														// sort the numbers to determine the elements needed to be checked

		vector<int> combination;
		get_combinations(candidates, 0, target, combinations, combination);
		return combinations;
	}

private:
	/* get all possible combinations given the index of the first element to be checked */
	void get_combinations(vector<int>& candidates, int head, int target, vector<vector<int>> &combinations, vector<int> &combination) {
		if (target == 0) {																				// a valid combination found
			combinations.push_back(combination);
			return;
		}

		while ((head < candidates.size()) && (candidates[head] <= target)) {
			combination.push_back(candidates[head]);
			get_combinations(candidates, head, target - candidates[head], combinations, combination);	// continue to search with the current target
			combination.pop_back();
			head++;
		}
	}
};