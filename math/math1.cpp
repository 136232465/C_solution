//leetcode 445 add tow numbers II
//
//You are given two non - empty linked lists representing two non - negative integers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up :
//What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.
//
//Example :
//
//	Input : (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 8 -> 0 -> 7
//






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
		ListNode* newHead = new ListNode(0);
		ListNode* curNode = l1;
		int len1 = 0, len2 = 0, tag = 0, firsttag = 0;
		while (curNode != NULL){
			curNode = curNode->next;
			len1++;
		}
		curNode = l2;
		while (curNode != NULL){
			curNode = curNode->next;
			len2++;
		}
		curNode = newHead;
		if (len1 > len2){
			while (len1 - len2){
				curNode->next = new ListNode(l1->val);
				--len1;
				curNode = curNode->next;
				l1 = l1->next;
			}
			while (len1){
				curNode->next = new ListNode(l1->val + l2->val);
				--len1;
				curNode = curNode->next;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		else {
			while (len2 - len1){
				curNode->next = new ListNode(l2->val);
				--len2;
				curNode = curNode->next;
				l2 = l2->next;
			}
			while (len2){
				curNode->next = new ListNode(l1->val + l2->val);
				--len2;
				curNode = curNode->next;
				l1 = l1->next;
				l2 = l2->next;
			}
		}

		if (Listtag(newHead->next) == 1){
			firsttag = 1;
		}
		curNode = newHead->next;
		while (curNode){
			curNode->val = (curNode->val + Listtag(curNode->next)) % 10;
			curNode = curNode->next;
		}
		if (firsttag == 1){
			ListNode* temp = new ListNode(1);
			temp->next = newHead->next;
			newHead->next = temp;
		}
		return newHead->next;
	}
private:
	int Listtag(ListNode* cur){
		if (cur == NULL){
			return 0;
		}
		if ((cur->val + Listtag(cur->next)) / 10 == 0){
			return 0;
		}
		else {
			return 1;
		}
	}

};