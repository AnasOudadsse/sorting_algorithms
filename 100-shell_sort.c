#include "sort.h"

void insertionSort(int *, long int, long int, size_t);

/**
* shell_sort - sorts using shell sort and knuths sequence
*
* @array: array to sort
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	long int num = 1;
	long int j, ko, tmp;

	if (size < 2)
		return;

	while (num < (long int)size / 3)
		num = num * 3 + 1;

	while (num > 0)
	{
		for (j = num; j < (long int) size; j++)
		{
			tmp = array[j];
			for (ko = j; ko >= num && array[ko - num] > tmp; ko = ko - num)
				array[ko] = array[ko - num];
			array[ko] = tmp;
		}
		print_array(array, size);
		num = (num - 1) / 3;
	}
}
