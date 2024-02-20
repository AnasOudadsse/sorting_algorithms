#include "sort.h"

/**
* listSwap - swaps two members of a list
* @cnode: current node
* @prev: previous node
* @head: head of list
*/
void listSwap(listint_t *cnode, listint_t *prev, listint_t **h)
{
	listint_t *tmp1 = cnode->next;
	listint_t *tmp2 = prev->prev;

	if (tmp1 != NULL)
		tmp1->prev = prev;
	if (tmp2 != NULL)
		tmp2->next = cnode;
	cnode->prev = tmp2;
	prev->next = tmp1;
	cnode->next = prev;
	prev->prev = cnode;
	if (*h == prev)
		*h = cnode;
	print_list(*h);
}

/**
* insertion_sort_list - sorts a list using insertion sort
* @list: double pointer to head of list
*/
void insertion_sort_list(listint_t **list)
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
