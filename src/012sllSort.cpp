/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int one_c = 0, two_c = 0,zero_c = 0;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while (temp != NULL)
	{
		if (temp->data == 1)
		{
			one_c++;
		}
		else if (temp->data == 2)
		{
			two_c++;
		}
		else if (temp->data==0)
		{
			zero_c++;
		}
		temp = temp->next;
	}
	temp = head;
	while (zero_c>0)
	{
			temp->data = 0;
			temp = temp->next;
			zero_c--;
		}
	while (one_c>0)
	{
		temp->data = 1;
		temp = temp->next;
		one_c--;
	}
	while (two_c>0)
	{
		temp->data = 2;
		temp = temp->next;
		two_c--;
	}
}
