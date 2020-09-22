#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
typedef struct {
	int data;
	struct Node* next;
}Node;
push(Node* root, int data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}
int pop(Node* root)
{
	Node* node = root->next;
	root->next = node->next;
	int out = node->data;
	free(node);
	return out;
}
showAll(Node* root)
{
	Node* cur = root->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
freeAll(Node* root)
{
	Node* node = root->next;
	while (node != NULL)
	{
		free(node);
		node = node->next;
	}
}
main()
{
	Node* head = malloc(sizeof(Node));
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	pop(head);
	showAll(head);
	freeAll(head);
}