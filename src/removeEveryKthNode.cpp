/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K) {

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	if (head == NULL || K <= 1)
		return NULL;
	for (int i = 1; temp->next != NULL; i++)
	{

		if (((i + 1) % K == 0) && (temp->next)->next == NULL)
		{
			temp->next = NULL;
			return head;
		}

		if ((i + 1) % K == 0)
		{

			temp->next = (temp->next)->next;
			temp = temp->next;
			i++;
		}
		else
		{
			temp = temp->next;
		}
	}
	return head;
}