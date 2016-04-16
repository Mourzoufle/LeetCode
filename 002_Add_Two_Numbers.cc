/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *root = new ListNode((l1->val + l2->val) % 10);
		int carry = (l1->val + l2->val >= 10 ? 1 : 0);
		l1 = l1->next;
		l2 = l2->next;
		ListNode *cur_node = root;
		while ((l1 != NULL) || (l2 != NULL) || (carry > 0)) {	// the next digit is nonzero
			int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
			cur_node->next = new ListNode(sum >= 10 ? sum - 10 : sum);
			carry = (sum >= 10 ? 1 : 0);
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
			cur_node = cur_node->next;
		}

		return root;
	}
};