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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1)									// the whole list need no reversion
			return head;

		ListNode *cur_node = head;
		for (int i = 0; i < k; i++) {
			if (cur_node == NULL)					// there are less than K nodes in the list - do not reverse
				return head;
			cur_node = cur_node->next;
		}
		cur_node = head;

		ListNode *prev_node = NULL;
		for (int i = 0; i < k; i++) {
			ListNode *next_node = cur_node->next;
			cur_node->next = prev_node;
			prev_node = cur_node;
			cur_node = next_node;
		}
		head->next = reverseKGroup(cur_node, k);	// continue to reverse the left nodes headed by cur_node
		return prev_node;
	}
};