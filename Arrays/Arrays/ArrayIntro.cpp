#include <iostream>
#include <cstdlib> // malloc, calloc, free
#include "ArrayIntro.h"

void arrayDeclarationTypes()
{
	// Declare an empty array
	int a[5];

	// Declare an array with initilization of all the array elements.
	int b[5] = {1, 2, 3, 4, 5};
	
	// Declare an array with partial values, the remaining elements are initialized by default datatyppe value.
	// 0 in case of integers.
	int c[5] = { 1, 2 };

	// Declare a single value with zero all the array elements are initialized with 0. As explained above.
	int d[5] = { 0 };

	// Do not declare the size of an array and the size is initialized based on the elements being initialized.
	int e[] = { 1, 4, 5, 6, 7, 3, 0 };
}

void arrayElementsAreContiguous()
{
	// Initialize an array.
	int a[5] = { 1,2,3,4,5 };
	
	// print the memory location of each element stored in the given array.
	for (size_t i = 0; i < 5; ++i)
	{
		// To get the address in integer format for easy readability we can use %d instead of %p as the format specifier.
		printf("Integer value %d at index %zu is stored in at %p\n", a[i], i, &a[i]);
		printf("Integer value %d at index %zu is stored in at %d\n", a[i], i, &a[i]);
	}
}

void staticAndDynamicArray()
{
	// Static array, the size is decided at the compile time.
	// This array is created on the stack.
	int a[5];

	// The size of an array can be decided at runtime, in C++ and not in C.
	// The example below will fail in C.
	// This may or may not work on different compilers or standards being used
	// On MSVS this is an error.
	
	// int n;
	// std::cout << "Please provide a size of the array to be created:" << std::endl;
	// std::cin >> n;
	// int b[n];

	// Using C++
	int* p; // The integer pointer variable is created on stack.
	p = new int[5]; // The memory is created on the heap.
	delete []p;

	// Using C
	int* p1;
	p1 = (int *)malloc(5 * sizeof(int));
	free(p1);
}

void increaseSizeOfArray()
{
	int* p, * q;
	p = (int*)malloc(5 * sizeof(int));
	if (p != NULL)
	{
		p[0] = 1;
		p[1] = 2;
		p[2] = 3;
		p[3] = 4;
		p[4] = 5;
		std::cout << "Values of the array P:" << std::endl;
		for (size_t i = 0; i < 5; ++i)
		{
			std::cout << p[i] << std::endl;
		}
	}

	std::cout << "Changing the array size." << std::endl;
	q = (int*)malloc(10 * sizeof(int));
	if (q != NULL && p != NULL)
	{
		for (size_t i = 0; i < 5; ++i)
		{
			q[i] = p[i];
		}
	}

	// Free the unused memory.
	free(p);
	p = q;
	q = nullptr;

	std::cout << "Printing Values of the updated array size" << std::endl;
	if (p != NULL)
	{
		for (size_t i = 0; i < 10; ++i)
		{
			std::cout << p[i] << std::endl;
		}
	}
	free(p);
}

void increaseSizeOfArray1()
{
	int* p;
	p = (int*)malloc(5 * sizeof(int));
	if (p != NULL)
	{
		p[0] = 1;
		p[1] = 2;
		p[2] = 3;
		p[3] = 4;
		p[4] = 5;
		std::cout << "Values of the array P:" << std::endl;
		for (size_t i = 0; i < 5; ++i)
		{
			std::cout << p[i] << std::endl;
		}
	}

	// This method can return null, if the reallocation if failed, leading us to not have access to original memory location.
	// This may cause the memory leak.
	p = (int*)realloc(p, 10 * sizeof(int));
	std::cout << "After realloc:\n";
	if (p != NULL)
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << p[i] << std::endl;
		}
	}
	free(p);
}

void twoDimensionArray()
{
	// Method 1: This array will be created inside a stack.
	int a[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

	std::cout << "Method 1: This array will be created inside a stack." << std::endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << a[i][j] << std::endl;
		}
	}

	// Method 2: Using a single pointer
	int* b[3];
	b[0] = new int[4];
	b[1] = new int[4];
	b[2] = new int[4];

	// We can also achieve this by using c style allocation.
	int* b1[3];
	b1[0] = (int*)malloc(4 * sizeof(int));
	b1[1] = (int*)malloc(4 * sizeof(int));
	b1[2] = (int*)malloc(4 * sizeof(int));

	// Correction number is used to maintain the sequence if number being added in array.
	int correctionNumber = 1;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			b[i][j] = i + j + correctionNumber;
		}
		correctionNumber = correctionNumber + 3;
	}

	// Print the array initialized.
	std::cout << "Method 2: Using a single pointer" << std::endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << b[i][j] << std::endl;
		}
	}

	// Method 3: Using a double pointer
	int **c;
	c = new int* [3];
	c[0] = new int[4];
	c[1] = new int[4];
	c[2] = new int[4];

	// We can also achieve this by using c style allocation.
	int** c1;
	c1 = (int**)malloc(3 * sizeof(int*));
	if (c1 == NULL) {
		c1[0] = (int*)malloc(4 * sizeof(int));
		c1[1] = (int*)malloc(4 * sizeof(int));
		c1[2] = (int*)malloc(4 * sizeof(int));
	}

	// Correction number is used to maintain the sequence if number being added in array.
	correctionNumber = 1;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			c[i][j] = i + j + correctionNumber;
		}
		correctionNumber = correctionNumber + 3;
	}

	// Print the array initialized.
	std::cout << "Method 3: Using a double pointer" << std::endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << c[i][j] << std::endl;
		}
	}
}