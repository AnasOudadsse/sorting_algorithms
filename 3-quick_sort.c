#include "sort.h"
#include <stdio.h>

/**
* sortPartition - finds the sortPartition for the quicksort
* @arr: arr to sort
* @l: lowest index of the sortPartition to sort
* @ko: highest index of the sortPartition to sort
* @size: size of the arr
* Return: index of the sortPartition
*/
size_t sortPartition(int *arr, ssize_t l, ssize_t ko, size_t size)
{
	ssize_t i, j;
	int s, im;

	im = arr[ko];
	i = l - 1;
	for (j = l; j < ko; j++)
	{
		if (arr[j] < im)
		{
			i++;
			if (i != j)
			{
				s = arr[i];
				arr[i] = arr[j];
				arr[j] = s;
				print_array(arr, size);
			}
		}
	}
	if (arr[ko] < arr[i + 1])
	{
		s = arr[i + 1];
		arr[i + 1] = arr[ko];
		arr[ko] = s;
		print_array(arr, size);
	}
	return (i + 1);
}

/**
* quicksort - sorts a sortPartition of an arr of integers
* @arr: arr to sort
* @l: lowest index of the sortPartition to sort
* @ko: highest index of the sortPartition to sort
* @size: size of the arr
*
* Return: void
*/
void quicksort(int *arr, ssize_t l, ssize_t ko, size_t size)
{
	ssize_t im;

	if (l < ko)
	{
		im = sortPartition(arr, l, ko, size);
		quicksort(arr, l, im - 1, size);
		quicksort(arr, im + 1, ko, size);

	}
}

/**
* quick_sort - sorts an array of integers in ascending order using the
* Quick sort algorithm
* @array: The array to sort
* @size: The size of the array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
