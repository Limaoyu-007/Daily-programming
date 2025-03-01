#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* creat_list_head()
{
	node* head, * p;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	for (int i = 0; i < 10; i++) {
		p = (node*)malloc(sizeof(node));
		p->data = rand() % 100;
		p->next = head->next;
		head->next = p;
	}
	return head;
}
node* creat_list_tail()
{
	node* head, * tail, * p;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	tail = head;
	for (int i = 0; i < 10; i++) {
		p = (node*)malloc(sizeof(node));
		p->data = rand() % 100;
		tail->next = p;
		p->next = NULL;
		tail = p;
	}
	return head;
}

void print_list(node *head) {
    node* p;
	p = head->next;
	
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
    printf("\n");
}

void add_list(node* head)
{
    int i, j;
    printf("你想在哪儿插入数字\n");
    scanf("%d", &i);
    printf("你想插入什么数字\n");
    scanf("%d", &j);
	node* p, * q;
    p = head;
    while(p) {
		if (p->data == i)
		{
			q = (node*)malloc(sizeof(node));
			q->data= j;
			q->next = p->next;
            p->next = q;
		}
        p = p->next;
    }
}

void delete_list(node* head)
{
	int i;
	printf("你想删除哪个数字\n");
    scanf("%d", &i);
	node* p, * q;
	p= head;
	while (p && p->next) {
		if (p->next->data == i)
		{
			q = p->next;
            p->next = q->next;
            free(q);
		}
        p = p->next;
	}
}

void search_list(node* head)
{
	int j;
	printf("你想查找第几个数字\n");
	scanf("%d", &j);
	node* p;
    p = head->next;
	for (int i = 0; i < j-1; i++)
	{
		p= p->next;
	}
    printf("%d\n", p->data);
}

void free_list(node* head)
{
    node* p, * q;
    p = head;
	while (p) {
		q = p->next;
        free(p);
        p = q;
	}
	printf("释放成功\n");
}



int main()
{
	node *head;

    head = creat_list_head();
    print_list(head);
    add_list(head);
	print_list(head);
	delete_list(head);
    print_list(head);
	search_list(head);
	free_list(head);
	return 0;
}