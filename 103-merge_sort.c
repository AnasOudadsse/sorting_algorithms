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
* splitmerge - recursively splits the array and merges the sorted arrays
* @strt: strting index (inclusive)
* @final: final index (exclusive)
* @arr: the arr to sort
* @cp: a cp of the arr
*
* Return: void
*/
void splitmerge(size_t strt, size_t final, int *arr, int *cp)
{
	size_t middle;

	if (final - strt < 2)
		return;
	middle = (strt + final) / 2;
	splitmerge(strt, middle, arr, cp);
	splitmerge(middle, final, arr, cp);
	merge(strt, middle, final, arr, cp);
	for (middle = strt; middle < final; middle++)
		cp[middle] = arr[middle];
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
	int *cp;

	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (varr = 0; varr < size; varr++)
		cp[varr] = array[varr];
	splitmerge(0, size, array, cp);
	free(cp);
}
