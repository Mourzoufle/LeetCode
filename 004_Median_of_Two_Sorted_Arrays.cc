class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double median = findKth(nums1, nums2, (nums1.size() + nums2.size()) / 2);
		if ((nums1.size() + nums2.size()) % 2 == 0) {						// number of the numbers is even - need to compute the average of the two medians
			median += findKth(nums1, nums2, (nums1.size() + nums2.size() - 1) / 2);
			median /= 2.0;
		}

		return median;
	}

private:
	/* find the Kth number in the combined array */
	double findKth(vector<int>& nums1, vector<int>& nums2, int idx) {
		if (nums2.size() > nums1.size())
			return findKth(nums2, nums1, idx);
		if (nums2.empty())
			return nums1[idx];

		int head1 = max(idx - (int)nums2.size(), 0), head2 = 0, tail1 = min((int)nums1.size() - 1, idx), tail2 = min((int)nums2.size() - 1, idx);
		while ((head1 < tail1) || (head2 < tail2)) {						// either nums1 or nums2 has two or more candidates
			if (head1 < tail1) {
				int mid = (head1 + tail1) / 2;
				if ((mid >= idx) || (nums1[mid] >= nums2[idx - mid - 1]))	// number at tail1 is a candidate - numbers larger than it are not
					tail1 = mid;
				else														// this number is too small - search in the larger ones
					head1 = mid + 1;
			}
			if (head2 < tail2) {
				int mid = (head2 + tail2) / 2;
				if ((mid >= idx) || (nums2[mid] >= nums1[idx - mid - 1]))	// number at tail2 is a candidate - numbers larger than it are not
					tail2 = mid;
				else														// this number is too small - search in the larger ones
					head2 = mid + 1;
			}
		}
		int res1 = INT_MAX, res2 = INT_MAX;
		if (head1 == tail1) {
			if ((head1 >= idx) || (nums1[head1] >= nums2[idx - head1 - 1]))	// this is a candidate
				res1 = nums1[head1];
		}
		if (head2 == tail2) {
			if ((head2 >= idx) || (nums2[head2] >= nums1[idx - head2 - 1]))	// this is a candidate
				res2 = nums2[head2];
		}
		return min(res1, res2);												// the smaller one is the true answer
	}
};