#include "recursionExercise.h"

// Sum of first n numbers provided using recursion.
int sumOfNaturalNumbers(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return sumOfNaturalNumbers(n - 1) + n;
}

// Find factorial of given number using recursion.
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return factorial(n - 1)* n;
}

// Find result for power of m  raised to n using recursion.
int power(int m, int n)
{
	if (n == 1)
	{
		return m;
	}
	return power(m, n - 1) * m;
}

int power1(int m, int n)
{
	if (n == 1)
	{
		return m;
	}
	if (n % 2 == 0)
	{
		return power1( (m * m), n / 2);
	}
	else
	{
		return m * power1((m * m), (n - 1) / 2);
	}
}

// Solve Taylor series using recursion.
double solveTaylorSeries(int x, int n)
{
	static double pow = 1;
	static double fact = 1;
	double result;
	if (n == 0)
	{
		return 1;
	}
	result = solveTaylorSeries(x, n - 1);
	pow = pow * x;
	fact = fact * n;
	return result + (pow / fact);
}

double solveTaylorSeriesUsingHornerRule(int x, int n)
{
	static double result = 1;
	if( n == 0 )
	{
		return result;
	}
	result = 1 + x * result / n;
	return solveTaylorSeriesUsingHornerRule(x, n -1);
}

double solveTaylorSeriesUsingIteration(int x, int n)
{
	double result = 1;
	for (; n > 0; --n)
	{
		result = 1 + x * result / n;
	}
	return result;
}

int fibonacciSeriesUsingRecursion(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fibonacciSeriesUsingRecursion(n - 2) + fibonacciSeriesUsingRecursion(n - 1);
}

int fibonacciSeriesUsingIteration(int n)
{
	if (n <= 1)
	{
		return n;
	}
	int t0 = 0;
	int t1 = 1;
	int nThTerm;
	for (int i = 2; i <= n; ++i)
	{
		nThTerm = t0 + t1;
		t0 = t1;
		t1 = nThTerm;
	}
	return nThTerm;
}

int combinationFormulaUsingRecursion(int n, int r)
{
	int fact1 = factorial(n); // n!
	int fact2 = factorial(r); // r!
	int fact3 = factorial(n-r); // (n-r)!
	return (fact1 / (fact2 * fact3));
}