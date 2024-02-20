#include "sort.h"

/**
* siftDown - fixes a heap
* @arr: the heap to fix
* @root: the root of the heap
* @final: the last index of the heap
* @size: size of the arr
*
* Return: void
*/
void siftDown(int *arr, size_t root, size_t final, size_t size)
{
	size_t left, right, switchh;
	int temp;

	while ((left = (2 * root) + 1) <= final)
	{
		switchh = root;
		right = left + 1;
		if (arr[switchh] < arr[left])
			switchh = left;
		if (right <= final && arr[switchh] < arr[right])
			switchh = right;
		if (switchh == root)
			return;
		temp = arr[root];
		arr[root] = arr[switchh];
		arr[switchh] = temp;
		print_array(arr, size);
		root = switchh;
	}
}

/**
* make_heap - makes a heap from an unsorted arr
* @arr: arr to turn into a heap
* @size: size of the arr
*
* Return: void
*/
void make_heap(int *arr, size_t size)
{
	size_t parent;

	for (parent = ((size - 1) - 1) / 2; 1; parent--)
	{
		siftDown(arr, parent, size - 1, size);
		if (parent == 0)
			break;
	}
}

/**
* heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t final;
	int temp;

	if (array == NULL || size < 2)
		return;
	make_heap(array, size);
	final = size - 1;
	while (final > 0)
	{
		temp = array[final];
		array[final] = array[0];
		array[0] = temp;
		print_array(array, size);
		final--;
		siftDown(array, 0, final, size);
	}
}
