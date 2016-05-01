class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> solutions;
		sort(candidates.begin(), candidates.end());

		vector<int> solution;
		get_solutions(candidates, 0, target, solutions, solution);
		return solutions;
	}

private:
	void get_solutions(vector<int>& candidates, int head, int target, vector<vector<int>> &solutions, vector<int> solution) {
		if (target == 0) {
			solutions.push_back(solution);
			return;
		}

		while ((head < candidates.size()) && (candidates[head] <= target)) {
			solution.push_back(candidates[head]);
			get_solutions(candidates, head, target - candidates[head], solutions, solution);
			solution.pop_back();
			head++;
		}
	}
};