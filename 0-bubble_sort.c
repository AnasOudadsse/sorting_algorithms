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
 * bubble_sort - Sort an array of integers in ascending order.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *arr, size_t size)
{
	size_t n, length = size;
	bool bubb = false;

	if (arr == NULL || size < 2)
		return;

	while (bubb == false)
	{
		bubb = true;
		for (n = 0; n < length - 1; n++)
		{
			if (arr[n] > arr[n + 1])
			{
				intSwap(arr + i, arr + i + 1);
				print_array(arr, size);
				bubb = false;
			}
		}
		length--;
	}
}
