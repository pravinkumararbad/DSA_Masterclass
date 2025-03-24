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