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

void iterativeBinarySearchExample()
{
	struct Array arr { {1, 2, 3, 4, 5, 6}, 10, 6 };
	int resIndex = iterativeBinarySearch(&arr, 5);
	if (resIndex >= 0)
	{
		printf("The key element is found at index %d.", resIndex);
	}
	else
	{
		printf("The key element is not found in the array.");
	}
}

void recursiveBinarySearchExample()
{
	struct Array arr { {1, 2, 3, 4, 5, 6}, 10, 6 };
	int resIndex = recursiveBinarySearch(&arr, 0, arr.length, 5);
	if (resIndex >= 0)
	{
		printf("The key element is found at index %d.", resIndex);
	}
	else
	{
		printf("The key element is not found in the array.");
	}
}

void getSetMinMaxAvgExample()
{
	// get example
	struct Array arr { {1, 2, 3, 4, 5, 6}, 10, 6 };
	printf("The get(3) for array [1, 2, 3, 4, 5, 6] is: %d\n\n", get(&arr, 3));

	// set example
	printf("Calling set(&arr, 3, 5) on array [1, 2, 3, 4, 5, 6]\n");
	set(&arr, 3, 5);
	display(arr);
	printf("\n\n");

	// Min example
	printf("Min example\n");
	printf("Calling min on array [1, 2, 3, 5, 5, 6] the min value is: %d\n\n", min(&arr));

	// Min example
	printf("Max example\n");
	printf("Calling min on array [1, 2, 3, 5, 5, 6] the min value is: %d\n\n", max(&arr));

	// Sum example
	printf("Sum example\n");
	printf("Calling sum on array [1, 2, 3, 5, 5, 6] the sum is: %d\n\n", sum(&arr));

	// Avg example
	printf("Avg example\n");
	printf("Calling avg on array [1, 2, 3, 5, 5, 6] the avg is: %lf\n\n", avg(&arr));

	// Avg example
	printf("Avg example\n");
	printf("Calling avg1 on array [1, 2, 3, 5, 5, 6] the avg is: %lf\n\n", avg1(&arr));
}