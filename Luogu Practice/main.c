/*
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* creatList()
{
	struct ListNode* head, * tail, * p;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	tail = head;
	for (int i = 0; i < 5; i++) {
		struct ListNode* newNode;
		newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = i;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
	p = head->next;
	for (int i = 0; i < 5; i++) {
		printf("%d", p->val);
		p = p->next;
	}
	return head;
}
int main()
{
	struct ListNode* head = creatList();

	struct ListNode* pre, * cur,* temp;
	cur = head->next;
	pre = NULL;
	while (cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;

	}
	struct ListNode* p = pre;
	for (int i = 0; i < 5; i++) {

		printf("%d ", p->val);
		p = p->next;
	}


	return 0;
}*/

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode less = { 0 };
	struct ListNode greater = { 0 };
	struct ListNode* p, * q;
	p = &less;
	q = &greater;
	while (head != NULL) {
		if (head->val < x) {
			p->next = head;
			p = p->next;
			head = head->next;
		}
		else {
			q->next = head;
			q = q->next;
			head = head->next;
		}
	}
	p->next = q->next;
	q->next = NULL;
	return less.next;
}