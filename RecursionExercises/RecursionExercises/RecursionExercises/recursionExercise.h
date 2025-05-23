#pragma once
#include <iostream>

// Sum of first n numbers provided using recursion.
int sumOfNaturalNumbers(int n);

// Find factorial of given number using recursion.
int factorial(int n);

// Find power using recursion. (m^n)
int power(int m, int n);

// Find result for power of m raised to n using recursion more efficiently.
// Explaination how we did it?
// power1(2,5)
//	  Since 5 is odd, we use the formula :
//      m×power1((m×m), (n−1) / 2)
//      2×power1(2×2, (5−1) / 2)
//      2×power1(4, 2)	-- 1
// 
//		Solving for eq 1 part 2,
//		For here we can consider it as second case of even power.
//      power1(4,2):
//	    Since 2 is even, we use :
//		power1(4×4, 2 / 2)
//		power1(16, 1) -- > Since n = 1, return 16;
//		Using equation 1 => power1(2,5)=2×16=32
int power1(int m, int n);

// Solving for Taylor series:
// e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)
// Here n is the times the series go on for.
double solveTaylorSeries(int x, int n);

// Solving for Taylor series using Hornet rule:
// e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)
// e^x = 1+x[ 1 + x/2 [ 1 + x/3 [ 1+ x/4 ] ] ]
double solveTaylorSeriesUsingHornerRule(int x, int n);

// Solving for Taylor series using Iterative method. (Loop)
// e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)
// e^x = 1+x[ 1 + x/2 [ 1 + x/3 [ 1+ x/4 ] ] ]
double solveTaylorSeriesUsingIteration(int x, int n);

// Writing code to print n th term in Fibonacci Series using recursion - Memoization
// fib can be achieved with this abse condition:
// if( n == 0 ), if( n == 1 ) return 0 and 1 respectively.
// if( n > 1 ) then ( fib(n-2) + fib(n-1) )
int fibonacciSeriesUsingRecursion(int n);

// Writing code to print n th term in Fibonacci Series using iteration. (Loop)
int fibonacciSeriesUsingIteration(int n);

// Let's code for combination formula. (nCr)
// nCr = n!/r!(n-r)!
int combinationFormulaUsingRecursion(int n, int r);

// Tower of Hanoi
// 1. Only one disk may be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
// 3. No disk may be placed on top of a disk that is smaller than it.
// https://en.wikipedia.org/wiki/Tower_of_Hanoi#/media/File:Tower_of_Hanoi_4.gif
// https://ianparberry.com/TowersOfHanoi/index64.html

// Single Disk
// Initial:              Final:
//  A     B     C         A     B     C
// [1]                               [1]
// 1. Move disk 1 from A to C using B

// Two Disk
// Initial:          |         Step 1       |        Step 2        |        Final
//  A     B     C    |     A     B     C    |    A     B     C     |    A     B     C
// [1]               |                      |                      |               [1]
// [2]               |    [2]   [1]         |         [1]   [2]    |               [2]
// 1. Move disk 1 from A to B using C
// 2. Move disk 2 from A to C using B
// 3. Mode disk 1 from B to C using A

// Three Disk
// Initial:        |      Step 1     |      Step 2     |      Step 3    |     Step 4     |      Step 5     |     Step 6     |      Step 7
//  A     B     C  |  A     B     C  |  A     B     C  |  A     B     C | A     B     C  |  A     B     C  | A     B     C  | A     B     C
// [1]             |                 |                 |                |                |                 |                |            [1]
// [2]             | [2]             |                 |       [1]      |      [1]       |                 |            [2] |            [2]
// [3]             | [3]         [1] | [3]   [2]   [1] | [3]   [2]      |      [2]   [3] | [1]   [2]   [3] |[1]         [3] |            [3]
// 1. Move disk 1 from A to C using B
// 2. Move disk 2 from A to B using C
// 3. Move disk 1 from C to A using B
// 4. Move disk 3 from A to C using B
// 5. Move disk 1 from B to A using C
// 6. Move disk 2 from B to C using A
// 7. Move disk 1 from A to C using B

// Algorithm:
// Single Disk: TOH(1, A, B, C)
// 1. Move Disk from A to C using B

// Two Disk:    TOH(2, A, B, C)
// 1. TOH (1, A, C, B)
// 2. Move disk from A to C using B just like single disk.
// 3. TOH (1, B, A, C)

// Three Disk:  TOH(3, A, B, C)
// Move  two disk to tower B this can be achieved with two disk move from tower A to C
// 1. TOH(2, A, C, B)
// 2. Move disk from A to C using B
// 3. TOH(2, B, A, C)
void towerOfHanoi(int disks, int t1, int t2, int t3);