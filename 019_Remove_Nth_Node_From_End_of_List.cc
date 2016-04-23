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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *tail = head;
		for (int i = 0; i < n; i++)		// find the n-th node after the head
			tail = tail->next;
		ListNode *cur_node = head;
		if (tail == NULL)				// the head is the node to be removed
			return cur_node->next;
		while (tail->next != NULL) {	// move cur_node and tail until tail is the last node in the list, then cur_node->next is the one to be removed
			cur_node = cur_node->next;
			tail = tail->next;
		}
		cur_node->next = cur_node->next->next;
		return head;
	}
}