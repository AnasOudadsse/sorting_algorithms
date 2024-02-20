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
	int i, maxim;
	int *counter = NULL, *copy = NULL;
	size_t j, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0, maxim = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > maxim)
			maxim = array[j];
	}
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(copy);
		return;
	}
	for (i = 0; i <= maxim; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[array[j]] += 1;
	for (i = 0; i <= maxim; i++)
	{
		temp = counter[i];
		counter[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[counter[copy[j]]] = copy[j];
		counter[copy[j]] += 1;
	}
	print_array(counter, maxim + 1);
	free(counter);
	free(copy);
}
