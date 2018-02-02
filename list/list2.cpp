#include <stdlib.h>

// Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//time O(n)
//space O(1)

//step 1:cut head into l1 and l2
//step 2:reverse l2
//step 3:merge l1 and l2
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return;
		}
		ListNode* l1 = head;
		ListNode* l2 = head->next;
		while (l2 != NULL && l2->next != NULL){
			l1 = l1->next;
			l2 = l2->next->next;
		}
		l2 = l1->next;
		l1->next = NULL;
		//  reverse L2
		ListNode* pre = l2;
		ListNode* cur = l2->next;
		ListNode* next;
		pre->next = NULL;
		while (cur != NULL) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		//merge l1 and l2
		l1 = head;
		l2 = pre;
		while (l2 != NULL) {
			ListNode* tmp = l1->next;
			l1->next = l2;
			l1 = l1->next;
			l2 = tmp;
		}
	}
};