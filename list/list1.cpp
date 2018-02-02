// leetcode 138 // Copy List with Random Pointer
// time O(n)
// space O(n)



// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *l1, *l2, *newhead;
		if (head == NULL){
			return NULL;
		}
		l1 = head;
		while (l1 != NULL){
			l2 = new RandomListNode(l1->label);
			l2->next = l1->next;
			l1->next = l2;
			l1 = l1->next->next;
		}
		l1 = head;
		while (l1 != NULL){
			if (l1->random != NULL){
				l1->next->random = l1->random->next;
			}
			l1 = l1->next->next;
		}
		newhead = head->next;
		l1 = head;
		l2 = l1->next;
		while (l2->next != NULL){
			l1->next = l2->next;
			l2->next = l2->next->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		l1->next = NULL;
		return newhead;

	}
};


//first step : a->b->c to a->a->b->b->c->c
//second step : add random pointer
//third strp : separation