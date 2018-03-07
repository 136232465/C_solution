// leetcode 148  sortList
// time O(nlogn)
// space O(1);
// use merge

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
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL){
			return head;
		}
		ListNode* left = head;
		ListNode* right = head->next->next;
		while (right != NULL && right->next != NULL){
			right = right->next->next;
			left = left->next;
		}
		right = left->next;
		left->next = NULL;
		return merge(sortList(head), sortList(right));
	}
private:
	ListNode* merge(ListNode* left, ListNode* right){
		ListNode* mergeList = new ListNode(0);
		ListNode* cur = mergeList;
		while (left != NULL && right != NULL){
			if (left->val < right->val){
				cur->next = left;
				cur = cur->next;
				left = left->next;
			}
			else {
				cur->next = right;
				cur = cur->next;
				right = right->next;
			}
		}
		if (left == NULL){
			cur->next = right;
		}
		else {
			cur->next = left;
		}
		return mergeList->next;
	}
};