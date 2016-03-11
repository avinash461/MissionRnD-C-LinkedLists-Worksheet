/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
void insert_at_begin(struct node** head_ref, int value, struct node* head);
struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	if (N<0)
	{
		N = N*-1;
	}

		
		int data = N % 10;
		N = N / 10;
		head->num = data;
		head->next = NULL;
		while (N)
		{
			insert_at_begin(&head, N % 10, head);
			N = N / 10;
		}
		return head;
	
}

void insert_at_begin(struct node** head_ref, int value, struct node* head)
{
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = value;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}