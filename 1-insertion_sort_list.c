#include "sort.h"

/**
 * swap_list - swaps two members of a list
 *
 * @curr: current node
 * @prev: previous node
 * @h: h of list
 */
void listSwap(listint_t *curr, listint_t *prev, listint_t **h)
{
    listint_t *tmp1 = curr->next;
    listint_t *tmp2 = prev->prev;

    if (tmp1 != NULL)
        tmp1->prev = prev;
    if (tmp2 != NULL)
        tmp2->next = curr;
    curr->prev = tmp2;
    prev->next = tmp1;
    curr->next = prev;
    prev->prev = curr;
    if (*h == prev)
        *h = curr;
    print_list(*h);
}

/**
 * insertion_sort_list - sorts a list using insertion sort
 *
 * @list: double pointer to h of lis
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr = NULL;
    listint_t *prev = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;
    prev = curr->prev;
    while (curr != NULL)
    {
        prev = curr->prev;
        while (prev != NULL && prev->n > curr->n)
        {
            swap_list(curr, prev, list);
            prev = curr->prev;
        }
        curr = curr->next;
    }
}
