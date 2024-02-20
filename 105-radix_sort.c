#include "sort.h"
#include <stdlib.h>

/**
* tenPower - calculates a positive power of 10
* @pow: power of 10 to calculate
*
* Return: the corresponding power of 10
*/
unsigned int tenPower(unsigned int pow)
{
	unsigned int i, total;

	total = 1;
	for (i = 0; i < pow; i++)
		total *= 10;
	return (total);
}

/**
* sortCount - sorts an array of integers in ascending order at a specific
* digit location using the Counting sort algorithm
* @arr: arr to sort
* @size: size of the arr to sort
* @integerr: integerr to sort by
*
* Return: 1 if there is a need to keep sorting, 0 if not
*/
unsigned int sortCount(int *arr, size_t size, unsigned int integerr)
{
	int i, count[10] = {0};
	int *copy = NULL;
	size_t j, tmp, result = 0;
	unsigned int d, p, s = 0;

	p = tenPower(integerr - 1);
	d = p * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		copy[j] = arr[j];
		if (arr[j] / d != 0)
			s = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(arr[j] % d) / p] += 1;
	for (i = 0; i < 10; i++)
	{
		tmp = count[i];
		count[i] = result;
		result += tmp;
	}
	for (j = 0; j < size; j++)
	{
		arr[count[(copy[j] % d) / p]] = copy[j];
		count[(copy[j] % d) / p] += 1;
	}
	free(copy);
	return (s);
}

/**
* radix_sort - sorts an array of integers in ascending order using
* the Radix sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	unsigned int j, s = 1;

	if (array == NULL || size < 2)
		return;
	for (j = 1; s == 1; j++)
	{
		s = sortCount(array, size, j);
		print_array(array, size);
	}
}
