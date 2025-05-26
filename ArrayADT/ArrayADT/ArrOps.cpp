#include "ArrOps.h"

// Example for displaying an array created in heap.
void display1(struct Array1 arr)
{
	printf("\nElements in the array are:\n");
	for (size_t i = 0; i < arr.length; ++i)
	{
		printf("%d ", arr.a[i]);
	}
}

// Display array elements.
void display(struct Array arr)
{
	printf("\nElements in the array are:\n");
	for (size_t i = 0; i < arr.length; ++i)
	{
		printf("%d ", arr.a[i]);
	}
}

// Add an element in an array. We know the length which signifies the next free location to add a new element.
// This will take 1 unit time to add the element making the time complexity of O(1).
void add(struct Array *arr, int x)
{
	if (arr->length < arr->size)
	{
		// Add a new element at index length and increment length to update the length to accomodate newly added element.
		arr->a[arr->length++] = x;
	}
}

// Insert an element in an array at a given index.
// This is not a operation like add, here we have to move all the other elements from the index provided to next available position.
// And add the element at given index
// Time complexity - Min: O(1) [Inserting at end of an array] | Max: O(n) [Inserting at start of an array]
void insert(struct Array *arr, int index, int x)
{
	// Verify that the index is positive, and should be less than the length of an array.
	if ( index >=0 && index <= arr->length && arr->size > arr->length)
	{
		for (size_t i = arr->length; i > index; --i)
		{
			arr->a[i] = arr->a[i-1];
		}
		arr->a[index] = x;
	}
	arr->length = ++arr->length;
}

// Deleting an element, will leave a blank index, which is not correct.
// We must shift all the element a to fill the blank index and update the length of the array.
// Similar to insert:
// Time complexity - Min: O(1) [Deleting the last element of an array] | Max: O(n) [Deleting first element of an array]
void Delete(struct Array *arr, int index)
{
	// Verify that the index is positive, and should be less than the length of an array.
	if (index >= 0 && index < arr->length )
	{
		for (size_t i = index; i < arr->length; ++i)
		{
			arr->a[i] = arr->a[i + 1];
		}
	}
	arr->length = --arr->length;
}

// Linear search of an element in an array.
int linearSearch(struct Array* arr, int key)
{
	for (size_t i = 0; i < arr->length; ++i)
	{
		if (arr->a[i] == key)
		{
			return i;
		}
	}
	return -1;
}

// Linear search of an element in an array, using transposition.
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int linearSearchWithTransposition(struct Array* arr, int key)
{
	for (size_t i = 0; i < arr->length; ++i)
	{
		if (arr->a[i] == key)
		{
			swap(&arr->a[i], &arr->a[i - 1]);
			return i;
		}
	}
	return -1;
}

int linearSearchWithMoveToHead(struct Array* arr, int key)
{
	for (size_t i = 0; i < arr->length; ++i)
	{
		if (arr->a[i] == key)
		{
			swap(&arr->a[i], &arr->a[0]);
			return i;
		}
	}
	return -1;
}