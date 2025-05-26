#pragma once
#include <stdio.h>
#include <stdlib.h>

// Struct to demonstrate an array created in heap.
struct Array1
{
	int* a;
	int size;
	int length;
};

// For further examples and to simplify we will use fixed size array which will not require initialization.
struct Array
{
	int a[20];
	int size;
	int length;
};

// Example for displaying an array created in heap.
void display1(struct Array1 arr);

// Display an array.
void display(struct Array arr);

// Add an element in an array.
void add(struct Array* arr, int x);

// Insert an element in an array at a given index.
void insert(struct Array* arr, int index, int x);

// Delete an element from a given index. [Using capital D is delebrate as delet is a keyword in C]
void Delete(struct Array* arr, int index);

// Search key element using linear search.
// If the element is found we return the index of the element if not -1 is returned.
int linearSearch(struct Array* arr, int key);

// Linear search of an element in an array, using transposition.
int linearSearchWithTransposition(struct Array* arr, int key);

int linearSearchWithMoveToHead(struct Array* arr, int key);