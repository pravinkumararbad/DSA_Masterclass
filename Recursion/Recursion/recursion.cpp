#include <stdio.h>
#include "recursion.h"

// Recursion function where it is perfomring some operation and then making a recursive call.
// This is an example of Tail Recursion.
void tailRecursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tailRecursion(n - 1);
    }
}

// Recursion function where a recursive call is made and then some operation is being perfomed.
// This is an example of Head Recursion.
void headRecursion(int n)
{
    if (n > 0)
    {
        headRecursion(n - 1);
        printf("%d ", n);
    }
}

int staticRecursion(int n)
{
    static int k = 0;
    if (n > 0)
    {
        k++;
        return staticRecursion(n - 1) + k;
    }
    return 0;
}

int globalK = 0;
int globalRecursion(int n)
{
    if (n > 0)
    {
        globalK++;
        return globalRecursion(n - 1) + globalK;
    }
    return 0;
}

void treeRecursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// Example for indirect recursion, here we will create 2 functions required for circular calls.

void indirectRecursionA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirectRecursionB(n - 1);
    }
}

void indirectRecursionB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        indirectRecursionA(n / 2);
    }
}

int nestedRecursion(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    return nestedRecursion(nestedRecursion(n + 11));
}