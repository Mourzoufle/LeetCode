class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums2.size() > nums1.size())									// assure that nums2 is not larger than nums1
			return findMedianSortedArrays(nums2, nums1);
		if (nums2.empty()) {
			int idx = (nums1.size() - 1) >> 1;
			return (nums1.size() % 2 > 0) ? nums1[idx] : ((nums1[idx] + nums1[idx + 1]) / 2.0);
		}

		int idx = (nums1.size() + nums2.size() - 1) >> 1;					// index of the median (if the total number of numbers is odd) or the former median (if is even)
		int head1 = max(idx - (int)nums2.size(), 0), head2 = 0, tail1 = idx, tail2 = nums2.size() - 1;
		while (head1 < tail1) {												// find a candidate in nums1 - Binary Search
			int mid = (head1 + tail1) >> 1;
			if (nums1[mid] >= nums2[idx - mid - 1])							// numbers larger than nums1[tail1] are not possible
				tail1 = mid;
			else															// numbers smaller than nums1[head1] are not possible
				head1 = mid + 1;
		}
		while (head2 < tail2) {												// find a candidate in nums2 - Binary Search
			int mid = (head2 + tail2) >> 1;
			if (nums2[mid] >= nums1[idx - mid - 1])							// numbers larger than nums2[tail1] are not possible
				tail2 = mid;
			else															// numbers smaller than nums2[head1] are not possible
				head2 = mid + 1;
		}
		int candidates[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
		if ((head1 <= tail1) && (nums1[head1] >= nums2[idx - head1 - 1])) {	// there is a candidate in nums1
			candidates[0] = nums1[head1];
			if (head1 < nums1.size() - 1)
				candidates[1] = nums1[head1 + 1];
		}
		if ((head2 <= tail2) && (nums2[head2] >= nums1[idx - head2 - 1])) {	// there is a candidate in nums2
			candidates[2] = nums2[head2];
			if (head2 < nums2.size() - 1)
				candidates[3] = nums2[head2 + 1];
		}
		double res = min(candidates[0], candidates[2]);
		if ((nums1.size() + nums2.size()) % 2 == 0) {						// need to compute the average
			if ((candidates[0] == candidates[2]) && (nums1.size() > 1))
				res += min(candidates[1], candidates[3]);
			else
				res += min(max(candidates[0], candidates[2]), min(candidates[1], candidates[3]));
			res /= 2;
		}

		return res;
	}
};
