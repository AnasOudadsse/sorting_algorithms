#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* TDMerge - sorts and merges the sub arrays in source
* @strt: starting index (inclusive) for the left sub array
* @mid: end index (exclusive) for the left sub array and
* starting index (inclusive) for the right sub array
* @final: final index (exclusive) for the right sub array
* @d: destination for data
* @s: s of data
*
* Return: void
*/
void TDMerge(size_t strt, size_t mid, size_t final, int *d, int *s)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(s + strt, mid - strt);
	printf("[right]: ");
	print_array(s + mid, final - mid);
	i = strt;
	j = mid;
	for (k = strt; k < final; k++)
	{
		if (i < mid && (j >= final || s[i] <= s[j]))
		{
			d[k] = s[i];
			i++;
		}
		else
		{
			d[k] = s[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(d + strt, final - strt);
}

/**
* TDSplitMerge - recursively splits the array and merges the sorted arrays
* @start: starting index (inclusive)
* @end: end index (exclusive)
* @array: the array to sort
* @copy: a copy of the array
*
* Return: void
*/
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
* merge_sort - sorts an array of integers in ascending order using the
* Merge sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
