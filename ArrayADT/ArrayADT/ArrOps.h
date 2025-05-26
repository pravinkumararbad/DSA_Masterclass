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
// Time Complexity: Min: O(1) | Max: O(n)
int linearSearch(struct Array* arr, int key);

// Linear search for key element in an array, using transposition.
int linearSearchWithTransposition(struct Array* arr, int key);
int linearSearchWithMoveToHead(struct Array* arr, int key);

// Search key element using binary search.
// Binary Search Analysis.
// 
//     +---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+
//     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
//     +---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+
//       0   1   2   3   4   5   6   7   8   9    10   11   12   13   14
// 
//              8                ---- 1 Search comparison
//           /     \
//         4         12          ---- 2 Search comparison
//       /  \       /   \ 
//     2     6    10    14       ---- 3 Search comparison
//    / \   / \   / \   / \
//   1   3 5   7 9  11 13 15     ---- 4 Search comparison
//   |   | |   | |   |  |  |
//   X   X X   X X   X  X  X     ---- 5 Failed search
// 
// The number of comparisons are dependant on the height of the tree, the time taken will be Min: O(1) Max: O(log(n))
// For unsuccessful search the time taken will be O(log(n))

// Simple analysis for Binary tree:
// Assume we have 16 elements in an array. How make times we will make the search to meet the successful search?
// This will be the case by the time we will find the key element or the mid index exceed the highindx.
// ((((16/2)/2)/2)/2) = 1, the times we divide the tree to make a final search is the heigh of tree which gives us time complexity.
// 16/2^4 => 2^4 = 16 => 4 = log2(16) => log2(n)

int iterativeBinarySearch(struct Array* arr, int key);
int recursiveBinarySearch(struct Array* arr, int lowIndx, int highIndx, int key);

// Retrieve the element present at the given element.
int get(struct Array* arr, int index);

// Set the value at a given index in an array.
void set(struct Array* arr, int index, int x);

// Return the largest value from the array elements.
int max(struct Array* arr);

// Return the smallest value from the array elements.
int min(struct Array* arr);

// Return the sum of all the elements of the array.
int sum(struct Array* arr);

// Returns the average of all the elements of array.
double avg(struct Array* arr);
double avg1(struct Array* arr);