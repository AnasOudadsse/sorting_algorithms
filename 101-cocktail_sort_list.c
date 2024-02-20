#include "sort.h"

/**
* listSwap - swaps two members of a list
*
* @curr: current node
* @prev: previous node
* @head: head of list
*/
void listSwap(listint_t *curr, listint_t *prev, listint_t **head)
{
	listint_t *temp1 = curr->next;
	listint_t *temp2 = prev->prev;

	if (temp1 != NULL)
		temp1->prev = prev;
	if (temp2 != NULL)
		temp2->next = curr;
	curr->prev = temp2;
	prev->next = temp1;
	curr->next = prev;
	prev->prev = curr;
	if (*head == prev)
		*head = curr;
	print_list(*head);
}

/**
* cocktail_sort_list - Sorts a Doubly linked list with cocktail sort
* @list: A Doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *maximum = NULL;
	listint_t *minimum = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	current = *list;
	do {
		while (current->next)
		{
			if (current->n > current->next->n)
				listSwap(current->next, current, list);
			else
				current = current->next;
		}
		maximum = current;
		while (current->prev != minimum)
		{
			if (current->n < current->prev->n)
				listSwap(current, current->prev, list);
			else
				current = current->prev;
		}
		minimum = current;
	} while (minimum != maximum);
}
