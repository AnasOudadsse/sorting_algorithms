#include "sort.h"

/**
* insertionSort_list - sorts a list using insertion sort
* @list: double pointer to head of list
*/
void insertionSortList(listint_t **list)
{
	listint_t *cnode = NULL;
	listint_t *prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cnode = (*list)->next;
	prev = cnode->prev;
	while (cnode != NULL)
	{
		prev = cnode->prev;
		while (prev != NULL && prev->n > cnode->n)
		{
			listSwap(cnode, prev, list);
			prev = cnode->prev;
		}
		cnode = cnode->next;
	}
}

/**
* cocktail_sort_list - Sorts a Doubly linked list with cocktail sort
* @list: A Doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *max = NULL;
	listint_t *min = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	cur = *list;
	do {
		while (cur->next)
		{
			if (cur->n > cur->next->n)
				swap_list(cur->next, cur, list);
			else
				cur = cur->next;
		}
		max = cur;
		while (cur->prev != min)
		{
			if (cur->n < cur->prev->n)
				swap_list(cur, cur->prev, list);
			else
				cur = cur->prev;
		}
		min = cur;
	} while (min != max);
}
