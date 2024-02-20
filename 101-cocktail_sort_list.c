#include "sort.h"

void listSwap(listint_t *cNode, listint_t *prev, listint_t **h);

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

/**
* swap_list - swaps two members of a list
*
* @cNode: current node
* @prev: previous node
* @h: h of list
*/
void listSwap(listint_t *cNode, listint_t *prev, listint_t **h)
{
	listint_t *tmp = cNode->next;
	listint_t *tmp2 = prev->prev;

	if (tmp != NULL)
		tmp->prev = prev;
	if (tmp2 != NULL)
		tmp2->next = cNode;
	cNode->prev = tmp2;
	prev->next = tmp;
	cNode->next = prev;
	prev->prev = cNode;
	if (*h == prev)
		*h = cNode;
	print_list(*h);
}
