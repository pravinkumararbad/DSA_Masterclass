#include "ArrExample.h"

void displayArrayExample1()
{
	struct Array1 arr;
	int n;
	printf("Enter size of an array:");
	scanf_s("%d", &arr.size);
	arr.a = (int*)malloc(arr.size * sizeof(int));
	arr.length = 0;

	printf("Enter number of numbers to be added.");
	scanf_s("%d", &n);

	printf("Enter all elements.\n");
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &arr.a[i]);
	}
	arr.length = n;

	display1(arr);
}

void displayArrayExample()
{
	struct Array arr { {1,2,3,4,5}, 20, 5 };
	display(arr);
}

void addArrayElementExample()
{
	struct Array arr { {1,2,3,4,5}, 10, 5 };
	add(&arr, 7);
	display(arr);
}

void insertArrayElementExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	insert(&arr, 4, 7);
	display(arr);
}

void deleteArrayElementExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	Delete(&arr, 2);
	display(arr);
}

void linearSearchExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	int resIndex = linearSearch(&arr, 3);
	if (resIndex >= 0)
	{
		printf("The key element is found at index %d.", resIndex);
	}
	else
	{
		printf("The key element is not found in the array.");
	}
}

void linearSearchWithTranspositionExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	int resIndex = linearSearchWithTransposition(&arr, 5);
	if (resIndex >= 0)
	{
		printf("The key element is found at index %d.", resIndex);
	}
	else
	{
		printf("The key element is not found in the array.");
	}

	// Verify that the index is indeed updated.
	display(arr);
}

void linearSearchWithMoveToHeadExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	int resIndex = linearSearchWithMoveToHead(&arr, 5);
	if (resIndex >= 0)
	{
		printf("The key element is found at index %d.", resIndex);
	}
	else
	{
		printf("The key element is not found in the array.");
	}
	display(arr);
}