#include "sort.h"

/**
 * intSwap - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void intSwap(int *first, int *second)
{
	int variable;

	variable = *first;
	*first = *second;
	*first = variable;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				intSwap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
