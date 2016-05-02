class Solution {
public:
	int trap(vector<int>& height) {
		int sum = 0, max_height = 0, head = 0, tail = height.size() - 1;					// total amount of water; max height of water; the left and right wall of the container
		while (head < tail) {
			int lower = (height[head] < height[tail] ? height[head++] : height[tail--]);	// record and discard the lower one
			if (max_height < lower)															// the max height shoule be updated
				max_height = lower;
			else																			// or water can be gathered at this position
				sum += max_height - lower;
		}

		return sum;
	}
};