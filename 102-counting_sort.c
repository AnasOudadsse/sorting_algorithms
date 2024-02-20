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
	int n, maxim;
	int *counter = NULL, *c = NULL;
	size_t m, tmp, t = 0;


	if (array == NULL || size < 2)
		return;
	c = malloc(sizeof(int) * size);
	if (c == NULL)
		return;
	for (m = 0, maxim = 0; m < size; m++)
	{
		c[m] = array[m];
		if (array[m] > maxim)
			maxim = array[m];
	}
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(c);
		return;
	}
	for (n = 0; n <= maxim; n++)
		counter[n] = 0;
	for (m = 0; m < size; m++)
		counter[array[m]] += 1;
	for (n = 0; n <= maxim; n++)
	{
		tmp = counter[n];
		counter[n] = t;
		t += tmp;
	}
	for (m = 0; m < size; m++)
	{
		array[counter[c[m]]] = c[m];
		counter[c[m]] += 1;
	}
	print_array(counter, maxim + 1);
	free(counter);
	free(c);
}
