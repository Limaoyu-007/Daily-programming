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
/*
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
}*/
/*选定反转链表
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* cratList()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));


	head->next = NULL;
	struct ListNode* p = head;

	for (int i = 0; i < 10; i++) {
		struct ListNode* newNode;
		newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newNode->val = i;
		newNode->next = p->next;
		p->next = newNode;
	}
	p = head->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	return head;
}

int main()
{
	struct ListNode* head,*p,*pre,*cur,*next;
	head = cratList();
	int left = 3;
	int right = 7;

	p = head;
	for (int i = 0; i < left - 1; i++) {
		p= p->next;
	}
	pre= p;
	cur = pre->next;
	for (int i = 0; i < right - left ; i++) {
		p= p->next;
	}
	next=cur->next;
	while (next!= p->next) {
		pre->next = next;
        cur->next = next->next;
        next->next = cur;
		cur = next;
        next = cur->next;
	}
	p= head->next;
	printf("\n");
	while(p) {
		printf("%d ", p->val);
		p= p->next;
	}






	return 0;
}*/