// leetcode 24 Swap Nodes in Pairs
// time O(n)
// space O(n)
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return head;
		}
		ListNode* next = head->next;
		head->next = swapPairs(head->next->next);
		next->next = head;
		return next;
	}
};
