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
	int *counter = NULL, *copy = NULL;
	size_t m, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (m = 0, maxim = 0; m < size; m++)
	{
		copy[m] = array[m];
		if (array[m] > maxim)
			maxim = array[m];
	}
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(copy);
		return;
	}
	for (n = 0; n <= maxim; n++)
		counter[n] = 0;
	for (m = 0; m < size; m++)
		counter[array[m]] += 1;
	for (n = 0; n <= maxim; n++)
	{
		temp = counter[n];
		counter[n] = total;
		total += temp;
	}
	for (m = 0; m < size; m++)
	{
		array[counter[copy[m]]] = copy[m];
		counter[copy[m]] += 1;
	}
	print_array(counter, maxim + 1);
	free(counter);
	free(copy);
}
