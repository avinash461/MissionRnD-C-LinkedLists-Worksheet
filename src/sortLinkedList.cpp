/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node *merging_sorted_array(struct node *a, struct node *b);
void merge_sort(struct node **head_ref);
struct node * sortLinkedList(struct node *head);
void  partioning(struct node *src, struct node **first_half, struct node **back_half);

struct node * sortLinkedList(struct node *head) {
	if (head != NULL)
	{
		merge_sort(&head);
		return head;
	}
	return NULL;
}
void merge_sort(struct node **head_ref)
{
	struct node *header = *head_ref;
	struct node *a;
	struct node *b;
	if (header == NULL || header->next == NULL)
	{
		return;
	}
	partioning(header, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref = merging_sorted_array(a, b);
}
struct node *merging_sorted_array(struct node *a, struct node *b)
{
	struct node *temp = NULL;
	if (a == NULL)
		return(b);

	else if (b == NULL)
		return(a);
	if (a->num <= b->num)
	{

		temp = a;
		temp->next = merging_sorted_array(a->next, b);
	}
	else  if (b->num <= a->num)
	{
		temp = b;
		temp->next = merging_sorted_array(a, b->next);
	}
	return(temp);
}
void  partioning(struct node *src, struct node **first_half, struct node **back_half)
{
	struct node *fast_ptr;
	struct node *slow_ptr;
	if (src == NULL || src->next == NULL)
	{
		*first_half = src;
		*back_half = NULL;
	}
	else
	{

		fast_ptr = src->next;
		slow_ptr = src;
		while (fast_ptr != NULL)
		{
			fast_ptr = fast_ptr->next;
			if (fast_ptr != NULL)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

		}
		*first_half = src;
		*back_half = slow_ptr->next;
		slow_ptr->next = NULL;
	}

}