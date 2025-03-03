#define _CRT_SECURE_NO_WARNINGS
/*
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
*/
/*
#include<stdio.h>
#include<stdlib.h>
st	ruct node
{
	int data;
	struct node* prev;
    struct node* next;
};
void print_list(struct node* head, struct node* tail) 
{
	struct node* q;
	q = head->next;
	while (q)
	{
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n");
	q = tail;
	while (q != head)
	{
		printf("%d ", q->data);
		q = q->prev;
	}
}
int main()
{
	struct node* head;
	struct node* tail;
	head = (struct node*)malloc(sizeof(struct node));
	head->prev = NULL;
	head->next = NULL;

    tail = head;

	for (int i = 0; i < 10; i++)
	{
        struct node* p;
        p = (struct node*)malloc(sizeof(struct node));
		
        p->data = rand() % 100;
		p->prev = tail;
		p->next = NULL;
        tail->next = p;
        tail = p;
	}
	//tail->next = head;
    //head->prev = tail;


	print_list(head, tail);

}
*/
/*
#include<stdio.h>

typedef struct
{
    int data[20];
	int top;
}Stack;

typedef struct
{
    int data[20];
	int top1;
    int top2;
}DoubleStack;

int main()
{
	Stack s;
	DoubleStack ds;

	/*for (int i = 0; i < 10; i++)
	{
		s.top++;
		s.data[s.top] = i;
	}
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", s.data[s.top]);
        s.top--;
    }

	ds.top1 = -1;
    ds.top2 = 20;







}
*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode;

typedef struct LinkStack
{
    struct StackNode* top;
    int count;
}LinkStack;

int main()
{
	LinkStack s;
	s.top = NULL;
    s.count = 0;
	for (int i = 0; i < 10; i++)
	{

		StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

		newNode->data = rand()%10;
		newNode->next = s.top;
		s.top = newNode;
		s.count++;
	}
	
	StackNode* temp = s.top;
	int data = temp->data;
	s.top = temp->next;
	free(temp);
	s.count--;

	printf("%d\n", data);

	printf("%d", s.top->data);
	return 0;
}*/
/*
#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* front;
	QNode* rear;
}LinkQueue;

int main()
{
	LinkQueue q;
	q.front = q.rear = NULL;

	for (int i = 0; i < 10; i++)
	{
		QNode* newNode = (QNode*)malloc(sizeof(QNode));
		newNode->data = rand()%10;
		newNode->next = NULL;
		printf("%d ", newNode->data);
		if (q.rear == NULL) {
			q.front = q.rear = newNode;
		}
		else {
			q.rear->next = newNode;
			q.rear = newNode;
		}
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		QNode* temp = q.front;
		int data = temp->data;
		q.front = q.front->next;

		printf("%d ", data);
		free(temp);
	}
	



}
*/