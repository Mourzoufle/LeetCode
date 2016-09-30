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
        ListNode *dummy = new ListNode(0);			// a dummy node pointing to the head
        ListNode *cur_digit = dummy;				// current digit
        bool carry = false;							// the carry digit - initially zero

        while (l1 || l2 || carry) {					// loop until both l1 and l2 are empty, and there is no carry digit
            cur_digit->next = new ListNode(0);
            cur_digit = cur_digit->next;
            if (l1) {
                cur_digit->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur_digit->val += l2->val;
                l2 = l2->next;
            }
            if (carry)
                cur_digit->val++;
            carry = cur_digit->val >= 10;
            cur_digit->val %= 10;
        }

        return dummy->next ? dummy->next : dummy;	// check if there are actually no digit after the dummy node
    }
};
