class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		Item *items = new Item[nums.size()];
		for (int i = 0; i < nums.size(); i++) {
			items[i].value = nums[i];
			items[i].idx = i;
		}
		sort(items, items + nums.size(), cmp);

		int idx_head = 0, idx_tail = nums.size() - 1;	// the smaller and larger items chosen to get the sum
		while (idx_head < idx_tail) {					// search until the smaller item meets the larger one
			int cur_sum = items[idx_head].value + items[idx_tail].value;
			if (cur_sum == target)						// solution found
				break;
			else if (cur_sum < target)
				idx_head++;
			else
				idx_tail--;
		}
		vector<int> indices = {items[idx_head].idx, items[idx_tail].idx};
		if (indices[0] > indices[1])					// the one with smaller index should be in the front
			swap(indices[0], indices[1]);

		return indices;
	}

private:
	/* Pair of the value and index of each item in the array */
	struct Item {
		int value;
		int idx;
	};

	/* compare function for sorting items */
	static bool cmp(const Item &a, const Item &b) { return a.value < b.value; }
};
