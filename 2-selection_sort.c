#include "sort.h"

/**
* selection_sort - sorts an array using selection sort
*
* @array: array to be sorted
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	unsigned int j, v;
	int minimum = 0, p = 0;

	for (j = 0; j < size; j += 1)
	{
		minimum = array[j];
		for (v = j; v < size; v += 1)
		{
			if (array[v] < minimum)
			{
				minimum = array[v];
				p = v;
			}
		}
		if (minimum != array[j])
		{
			array[p] = array[j];
			array[j] = minimum;
			print_array(array, size);
		}

	}
}
