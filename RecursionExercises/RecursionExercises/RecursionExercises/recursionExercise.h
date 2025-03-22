#pragma once
#include <iostream>

// Sum of first n numbers provided using recursion.
int sumOfNaturalNumbers(int n);

// Find factorial of given number using recursion.
int factorial(int n);

// Find power using recursion. (m^n)
int power(int m, int n);
int power1(int m, int n);

// Solving for Taylor series:
// e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)+(x^4/4!)
// Here n is the times the series go on for.
double solveTaylorSeries(int x, int n);
double solveTaylorSeriesUsingHornerRule(int x, int y);