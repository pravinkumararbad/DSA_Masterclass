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

void reverseArrayExample()
{
	struct Array arr = { {1,2,3,4,5}, 20, 5 };
	
	// Reverse an array example
	printf("Calling an reverse on array containing {1,2,3,4,5}\n");
	reverse(&arr);
	display(arr);

	struct Array reverseAltArr = { {1,2,3,4,5}, 20, 5 };
	printf("\nCalling an reverse on array containing {1,2,3,4,5}\n");
	reverseAlt(&reverseAltArr);
	display(arr);

	struct Array reverseBetterAltArr = { {1,2,3,4,5}, 20, 5 };
	printf("\nCalling an reverse on array containing {1,2,3,4,5}\n");
	reverseBetterAlt(&reverseBetterAltArr);
	display(arr);
}

void leftShiftExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	printf("\nCalling left shift on array containing {1,2,3,4,5}\n");
	leftShift(&arr);
	display(arr);
}

void leftRotateExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	printf("\nCalling left rotate on array containing {1,2,3,4,5}\n");
	leftRotate(&arr);
	display(arr);
}

void rightShiftExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	printf("\nCalling right shift on array containing {1,2,3,4,5}\n");
	rightShift(&arr);
	display(arr);
}

void rightRotateExample()
{
	struct Array arr { {1, 2, 3, 4, 5}, 10, 5 };
	printf("\nCalling right rotate on array containing {1,2,3,4,5}\n");
	rightRotate(&arr);
	display(arr);
}

void insertElementInSortedArrayExample()
{
	struct Array arr { {4, 8, 13, 16, 35}, 10, 5 };
	printf("\nCalling insert element in sorted array {4,8,13,16,35}\n");
	insertElementInSortedArray(&arr, 10);
	display(arr);
}

void isArraySortedExample()
{
	struct Array arr { {4, 8, 13, 16, 35}, 10, 5 };
	printf("\nCalling is array sorted on {4,8,13,16,35}\n");
	if (isArraySorted(&arr))
	{
		printf("Array is sorted.\n");
	}
	else
	{
		printf("Array is not sorted.\n");
	}

	struct Array arr1 { {4, 8, 19, 16, 35}, 10, 5 };
	printf("\nCalling is array sorted on {4, 8, 19, 16, 35}\n");
	if (isArraySorted(&arr1))
	{
		printf("Array is sorted.\n");
	}
	else
	{
		printf("Array is not sorted.\n");
	}
}

void segregatePosNegNumbersExample()
{
	struct Array arr { {-6, 3, -8, 10, 9, -7, -9, 12}, 10, 8 };
	segregatePosNegNumbers(&arr);
	display(arr);
}

void mergeSortedArraysExample()
{
	struct Array arr1 { {1, 2, 3, 4, 5, 14}, 10, 6 };
	struct Array arr2 { {6, 7, 8, 9, 10}, 10, 5 };
	printf("\nCalling mergeSortedArrays on {1, 2, 3, 4, 5, 14} and {6, 7, 8, 9, 10}\n");
	struct Array* mergedArr = mergeSortedArrays(&arr1, &arr2);
	display(*mergedArr);
}
