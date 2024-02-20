#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order using the
* Bubble sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t j, m, k;
	int s;

	if (array == NULL || size < 2)
		return;

	m = size;
	while (m > 0)
	{
		k = 0;
		for (j = 0; j < m - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				s = array[j];
				array[j] = array[j + 1];
				array[j + 1] = s;
				k = j + 1;
				print_array(array, size);
			}
		}
		m = k;
	}
}
