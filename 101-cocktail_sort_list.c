#include "sort.h"

/**
* insertionSortList - sorts a list using insertion sort
* @list: double pointer to head of list
*/
void insertionSortList(listint_t **list)
{
	listint_t *cnode = NULL;
	listint_t *prv = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cnode = (*list)->next;
	prv = cnode->prv;
	while (cnode != NULL)
	{
		prv = cnode->prv;
		while (prv != NULL && prv->n > cnode->n)
		{
			listSwap(cnode, prv, list);
			prv = cnode->prv;
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
	listint_t *cNode;
	listint_t *maximum = NULL;
	listint_t *minimum = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	cNode = *list;
	do {
		while (cNode->next)
		{
			if (cNode->n > cNode->next->n)
				swap_list(cNode->next, cNode, list);
			else
				cNode = cNode->next;
		}
		maximum = cNode;
		while (cNode->prev != minimum)
		{
			if (cNode->n < cNode->prev->n)
				swap_list(cNode, cNode->prev, list);
			else
				cNode = cNode->prev;
		}
		minimum = cNode;
	} while (minimum != maximum);
}
