class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area = 0, head = 0, tail = height.size() - 1;	// max area; the first and last line under checking
		while (head < tail) {
			int cur_area = min(height[head], height[tail]) * (tail - head);
			if (max_area < cur_area)							// larger area found
				max_area = cur_area;
			if (height[head] < height[tail])
				head++;
			else
				tail--;
		}

		return max_area;
	}
};