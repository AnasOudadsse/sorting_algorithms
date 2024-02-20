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
	int *counter = NULL, *copy = NULL;
	size_t j, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(copy);
		return;
	}
	for (i = 0; i <= max; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[array[j]] += 1;
	for (i = 0; i <= max; i++)
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
	print_array(counter, max + 1);
	free(counter);
	free(copy);
}
