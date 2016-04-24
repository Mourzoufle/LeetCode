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
	ListNode* swapPairs(ListNode* head) {
		ListNode *cur_node = head, *prev_node = NULL;
		if ((head != NULL) && (head->next != NULL))					// change the head if needed
			head = head->next;
		while ((cur_node != NULL) && (cur_node->next != NULL)) {	// swap nodes when there are two more nodes left
			ListNode *next_node = cur_node->next;
			cur_node->next = next_node->next;
			next_node->next = cur_node;
			if (prev_node != NULL)									// update the next node of the prev_node - should be next_node
				prev_node->next = next_node;
			prev_node = cur_node;									// save cur_node - if there are still two more nodes left, the next node of it should be updated
			cur_node = cur_node->next;
		}

		return head;
	}
};