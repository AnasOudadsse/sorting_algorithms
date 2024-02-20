#include "sort.h"
#include "stdlib.h"

/**
* counting_sort - sorts an array of integers in ascending order using the
* Counting sort algorithm
* @array: array to sort
* @size: size of the array to sort
*
* Return: void
*/
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *cnt = NULL, *cp = NULL;
	size_t i, tmp, totale = 0;


	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (i = 0, max = 0; i < size; i++)
	{
		cp[i] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(cp);
		return;
	}
	for (i = 0; i <= max; i++)
		cnt[i] = 0;
	for (i = 0; i < size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i <= max; i++)
	{
		tmp = cnt[i];
		cnt[i] = totale;
		totale += tmp;
	}
	for (i = 0; i < size; i++)
	{
		array[cnt[cp[i]]] = cp[i];
		cnt[cp[i]] += 1;
	}
	print_array(cnt, max + 1);
	free(cnt);
	free(cp);
}
