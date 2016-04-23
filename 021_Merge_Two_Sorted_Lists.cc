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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);			// a dummy node whose next node is the head
		ListNode *cur_node = head;
		while ((l1 != NULL) && (l2 != NULL)) {		// compare the heads of l1 and l2 when both of them are not null
			if (l1->val < l2->val) {				// next node is the head of l1
				cur_node->next = l1;
				l1 = l1->next;
			}
			else {									// next node is the head of l2
				cur_node->next = l2;
				l2 = l2->next;
			}
			cur_node = cur_node->next;
		}
		cur_node->next = (l1 == NULL ? l2 : l1);	// add the remaining elements

		return head->next;
	}
};