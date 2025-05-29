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
	printf("\n");
}

// Add an element in an array. We know the length which signifies the next free location to add a new element.
// This will take 1 unit time to add the element making the time complexity of O(1).
void add(struct Array1 *arr, int x)
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
	for (int i = 0; i < arr->length; ++i)
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
	for (int i = 0; i < arr->length; ++i)
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
	for (int i = 0; i < arr->length; ++i)
	{
		if (arr->a[i] == key)
		{
			swap(&arr->a[i], &arr->a[0]);
			return i;
		}
	}
	return -1;
}

int iterativeBinarySearch(struct Array* arr, int key)
{
	int lowIndx = 0;
	int highIndx = arr->length;
	int midIndx = 0;

	while (lowIndx <= highIndx)
	{
		midIndx = (lowIndx + highIndx) / 2;
		if (arr->a[midIndx] == key)
		{
			return midIndx;
		}
		else if (key < arr->a[midIndx])
		{
			highIndx = midIndx - 1;
		}
		else
		{
			lowIndx = midIndx + 1;
		}
	}
	return -1;
}

int recursiveBinarySearch(struct Array* arr, int lowIndx, int highIndx, int key)
{
	int midIndx = 0;

	if (lowIndx <= highIndx)
	{
		midIndx = (lowIndx + highIndx) / 2;
		if (arr->a[midIndx] == key)
		{
			return midIndx;
		}
		else if( key < arr->a[midIndx])
		{
			return recursiveBinarySearch(arr, lowIndx, midIndx - 1, key);
		}
		else
		{
			return recursiveBinarySearch(arr, midIndx + 1, highIndx, key);
		}
	}
	return -1;
}

int get(struct Array* arr, int index)
{
	if ( index >= 0 && index < arr->length )
	{
		return arr->a[index];
	}
	return -1;
}

void set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		arr->a[index] = x;
	}
}

int max(struct Array* arr)
{
	int max = arr->a[0];
	for (size_t i = 0; i < arr->length; ++i)
	{
		if (max < arr->a[i])
		{
			max = arr->a[i];
		}
	}
	return max;
}

int min(struct Array* arr)
{
	int min = arr->a[0];
	for (size_t i = 0; i < arr->length; ++i)
	{
		if (min > arr->a[i])
		{
			min = arr->a[i];
		}
	}
	return min;
}

int sum(struct Array* arr)
{
	int sum = 0;
	for (size_t i = 0; i < arr->length; ++i)
	{
		sum += arr->a[i];
	}
	return sum;
}

double avg(struct Array* arr)
{
	double sum = 0;
	for (size_t i = 0; i < arr->length; ++i)
	{
		sum += arr->a[i];
	}
	return sum/arr->length;
}

double avg1(struct Array* arr)
{
	return (double)sum(arr) / arr->length;
}

void reverse(struct Array* arr)
{
	// Create a auxillary array
	int* auxArr = (int*)malloc(arr->length * sizeof(int));
	for (int i = arr->length - 1, j = 0; i >= 0; --i, ++j)
	{
		auxArr[j] = arr->a[i];
	}

	for (int i = 0; i < arr->length; ++i)
	{
		arr->a[i] = auxArr[i];
	}
}

void reverseAlt(struct Array* arr)
{
	// Create a auxillary array
	struct Array auxArr { {}, 20, 0 };
	for (int i = arr->length - 1; i >= 0; --i)
	{
		auxArr.a[auxArr.length++] = arr->a[i];
	}

	// Copy the elements back to original array.
	for (size_t i = 0; i < arr->length; ++i)
	{
		arr->a[i] = auxArr.a[i];
	}
}

void reverseBetterAlt(struct Array* arr)
{
	// Start swap operation
	for (int i = 0, j = arr->length - 1; i < j; ++i, --j)
	{
		swap(&arr->a[i], &arr->a[j]);
	}
}

void leftShift(struct Array* arr)
{
	for (int i = 0, j = 1; i < arr->length; ++i, ++j)
	{
		arr->a[i] = arr->a[j];
	}
}

void leftRotate(struct Array* arr)
{
	// Nothing to rotate
	if (arr->length <= 1)
	{
		return;
	}
	int firstElement = arr->a[0];
	for (int i = 0, j = 1; i < arr->length; ++i, ++j)
	{
		arr->a[i] = arr->a[j];
	}
	arr->a[arr->length - 1] = firstElement;
}

void rightShift(struct Array* arr)
{
	for (int i = arr->length - 1; i > 0; --i)
	{
		arr->a[i] = arr->a[i - 1];
	}
	arr->a[0] = 0;
}

void rightRotate(struct Array* arr)
{
	// Nothing to rotate
	if (arr->length <= 1)
	{
		return;
	}
	int lastElement = arr->a[arr->length - 1];
	for (int i = arr->length - 1; i > 0; --i)
	{
		arr->a[i] = arr->a[i - 1];
	}
	arr->a[0] = lastElement;
}

void insertElementInSortedArray(struct Array* arr, int x)
{
	// Check the size of an array is greater than the length so we can insert an element.
	if (arr->size > arr->length)
	{
		int indx = arr->length - 1;
		while (arr->a[indx] > x)
		{
			arr->a[indx + 1] = arr->a[indx];
			--indx;
		}

		// Add the element at the sorted position and increse the the length
		arr->a[indx + 1] = x;
		arr->length++;
	}
}

bool isArraySorted(struct Array* arr)
{
	for (int indx = 0; indx < arr->length - 1; ++indx)
	{
		if (arr->a[indx] > arr->a[indx + 1])
		{
			return false;
		}
	}
	return true;
}

void segregatePosNegNumbers(struct Array* arr)
{
	int i = 0;
	int j = arr->length - 1;
	
	// Run a look till the index i is less than j.
	while (i < j)
	{
		// if the element at index i is less than 0, increment the index i as we want to keep -ve in left side.
		while (arr->a[i] < 0)
		{
			++i;
		}

		// if the element at index j is greater than 0, decrement the index j as we want to keep +ve in right side.
		while (arr->a[j] >= 0)
		{
			--j;
		}

		// Swap the elements only when the value of index i is less than index j. If the index i is greater it suggests,
		// We have completed traversal through all the elements in an array.
		if (i < j)
		{
			swap(&arr->a[i], &arr->a[j]);
		}
	}
}

// Merge and create a new sorted array
struct Array* mergeSortedArrays(struct Array* arr1, struct Array* arr2)
{
	// struct Array mergedArr { {0}, 20, 10 };
	struct Array* mergedArr = (struct Array*)malloc(sizeof(struct Array));
	if (mergedArr == NULL)
	{
		return (struct Array*)malloc(sizeof(struct Array));
	}
	mergedArr->a[0] = 0;
	mergedArr->size = 20;
	mergedArr->length = arr1->length + arr2->length;

	// Process merge
	int arr1Indx = 0;
	int arr2Indx = 0;
	int mergeArrIndx = 0;
	while (arr1Indx < arr1->length && arr2Indx < arr2->length)
	{
		if (arr1->a[arr1Indx] < arr2->a[arr2Indx])
		{
			mergedArr->a[mergeArrIndx++] = arr1->a[arr1Indx++];
		}
		else
		{
			mergedArr->a[mergeArrIndx++] = arr2->a[arr2Indx++];
		}
	}
	
	// Combile if-for in while
	while (arr1Indx < arr1->length)
	{
		mergedArr->a[mergeArrIndx] = arr1->a[arr1Indx++];
	}
	
	// Copying data using if-while combination
	if(arr2Indx < arr2->length)
	{
		for ( int j = arr2Indx; j < arr2->length; ++j)
		{
			mergedArr->a[mergeArrIndx++] = arr2->a[j];
		}
	}
	return mergedArr;
}

struct Array* unionArray(struct Array* arr1, struct Array* arr2)
{
	// struct Array mergedArr { {0}, 20, 10 };
	struct Array* unionArray = (struct Array*)malloc(sizeof(struct Array));
	if (unionArray == NULL)
	{
		return (struct Array*)malloc(sizeof(struct Array));
	}
	unionArray->a[0] = 0;
	unionArray->size = 20;

	// Process merge
	int arr1Indx = 0;
	int arr2Indx = 0;
	int unionArrIndx = 0;
	while (arr1Indx < arr1->length && arr2Indx < arr2->length)
	{
		if (arr1->a[arr1Indx] < arr2->a[arr2Indx])
		{
			unionArray->a[unionArrIndx++] = arr1->a[arr1Indx++];
		}
		else if(arr1->a[arr1Indx] > arr2->a[arr2Indx])
		{
			unionArray->a[unionArrIndx++] = arr2->a[arr2Indx++];
		}
		else
		{
			unionArray->a[unionArrIndx++] = arr1->a[arr1Indx++];
			arr2Indx++;
		}
	}

	for (; arr1Indx < arr1->length; ++arr1Indx)
	{
		unionArray->a[unionArrIndx++] = arr1->a[arr1Indx];
	}

	for (; arr2Indx < arr2->length; ++arr2Indx)
	{
		unionArray->a[unionArrIndx++] = arr2->a[arr2Indx];
	}
	unionArray->length = unionArrIndx;
	return unionArray;
}

struct Array* intersectionArray(struct Array* arr1, struct Array* arr2)
{
	struct Array* intersectionArray = (struct Array*)malloc(sizeof(struct Array));
	if (intersectionArray == NULL)
	{
		return (struct Array*)malloc(sizeof(struct Array));
	}
	intersectionArray->a[0] = 0;
	intersectionArray->size = 20;

	// Process merge
	int arr1Indx = 0;
	int arr2Indx = 0;
	int intersectionArrIndx = 0;
	while (arr1Indx < arr1->length && arr2Indx < arr2->length)
	{
		if (arr1->a[arr1Indx] < arr2->a[arr2Indx])
		{
			arr1Indx++;
		}
		else if (arr1->a[arr1Indx] > arr2->a[arr2Indx])
		{
			arr2Indx++;
		}
		else
		{
			intersectionArray->a[intersectionArrIndx++] = arr1->a[arr1Indx++];
			arr2Indx++;
		}
	}

	intersectionArray->length = intersectionArrIndx;
	return intersectionArray;
}

struct Array* differenceArrOp(struct Array* arr1, struct Array* arr2)
{
	struct Array* differenceArray = (struct Array*)malloc(sizeof(struct Array));
	if (differenceArray == NULL)
	{
		return (struct Array*)malloc(sizeof(struct Array));
	}
	differenceArray->a[0] = 0;
	differenceArray->size = 20;

	// Process merge
	int arr1Indx = 0;
	int arr2Indx = 0;
	int diffArrIndx = 0;
	while (arr1Indx < arr1->length && arr2Indx < arr2->length)
	{
		if (arr1->a[arr1Indx] < arr2->a[arr2Indx])
		{
			differenceArray->a[diffArrIndx++] = arr1->a[arr1Indx++];
		}
		else if (arr1->a[arr1Indx] > arr2->a[arr2Indx])
		{
			arr2Indx++;
		}
		else
		{
			arr1Indx++;
			arr2Indx++;
		}
	}

	for (; arr1Indx < arr1->length; ++arr1Indx)
	{
		differenceArray->a[diffArrIndx++] = arr1->a[arr1Indx];
	}
	differenceArray->length = diffArrIndx;
	return differenceArray;
}