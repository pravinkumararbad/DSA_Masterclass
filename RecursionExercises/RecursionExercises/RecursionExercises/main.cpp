#include "recursionExercise.h"

int main()
{
	printf("%d\n", sumOfNaturalNumbers(5));
	printf("%d\n", factorial(5));
	printf("%d\n", power(5, 5));
	printf("%d\n", power1(5, 5));
	printf("%lf\n", solveTaylorSeries(3, 10));
	printf("%lf\n", solveTaylorSeriesUsingHornerRule(3, 10));
	printf("%lf\n", solveTaylorSeriesUsingIteration(3, 10));
	printf("%d\n", fibonacciSeriesUsingRecursion(18));
	printf("%d\n", fibonacciSeriesUsingIteration(18));
	printf("%d\n", combinationFormulaUsingRecursion(9, 4));
	towerOfHanoi(3, 1, 2, 3);
	return 0;
}