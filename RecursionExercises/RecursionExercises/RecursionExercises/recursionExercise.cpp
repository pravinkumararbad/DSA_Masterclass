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