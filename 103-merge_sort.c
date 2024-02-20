#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* TDMerge - sorts and merges the sub arrays in source
* @strt: starting index (inclusive) for the left sub array
* @mid: final index (exclusive) for the left sub array and
* starting index (inclusive) for the right sub array
* @final: final index (exclusive) for the right sub array
* @d: destination for data
* @s: s of data
*
* Return: void
*/
void TDMerge(size_t strt, size_t mid, size_t final, int *d, int *s)
{
	size_t j, m, ko;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(s + strt, mid - strt);
	printf("[right]: ");
	print_array(s + mid, final - mid);
	m = strt;
	m = mid;
	for (ko = strt; ko < final; ko++)
	{
		if (m < mid && (m >= final || s[m] <= s[m]))
		{
			d[ko] = s[m];
			m++;
		}
		else
		{
			d[ko] = s[m];
			m++;
		}
	}
	printf("[Done]: ");
	print_array(d + strt, final - strt);
}

/**
* TDSplitMerge - recursively splits the array and merges the sorted arrays
* @strt: starting index (inclusive)
* @final: final index (exclusive)
* @array: the array to sort
* @cp: a copy of the array
*
* Return: void
*/
void TDSplitMerge(size_t strt, size_t final, int *array, int *cp)
{
	size_t mid;

	if (final - strt < 2)
		return;
	mid = (strt + final) / 2;
	TDSplitMerge(strt, mid, array, cp);
	TDSplitMerge(mid, final, array, cp);
	TDMerge(strt, mid, final, array, cp);
	for (mid = strt; mid < final; mid++)
		cp[mid] = array[mid];
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
	size_t j;
	int *cp;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (j = 0; j < size; j++)
		cp[j] = array[j];
	TDSplitMerge(0, size, array, cp);
	free(cp);
}
