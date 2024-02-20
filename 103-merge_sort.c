#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge - sorts and merges the sub arrays in source
* @strt: starting index (inclusive) for the left sub array
* @mid: end index (exclusive) for the left sub array and
* starting index (inclusive) for the right sub array
* @final: final index (exclusive) for the right sub array
* @d: destination for data
* @s: s of data
*
* Return: void
*/
void merge(size_t strt, size_t mid, size_t final, int *d, int *s)
{
	size_t varr, i, ko;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(s + strt, mid - strt);
	printf("[right]: ");
	print_array(s + mid, final - mid);
	varr = strt;
	i = mid;
	for (ko = strt; ko < final; ko++)
	{
		if (varr < mid && (i >= final || s[varr] <= s[i]))
		{
			d[ko] = s[varr];
			varr++;
		}
		else
		{
			d[ko] = s[i];
			i++;
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
	merge(start, middle, end, array, copy);
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
	size_t varr;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (varr = 0; varr < size; varr++)
		copy[varr] = array[varr];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
