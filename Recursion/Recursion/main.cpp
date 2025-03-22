#include <stdio.h>
#include "recursion.h"

int main()
{
	headRecursion( 4 );
	printf( "\n" );

	tailRecursion( 4 );
    printf( "\n" );
	
	printf( "%d", staticRecursion( 5 ) );
	printf( "\n" );

	printf( "%d", globalRecursion( 5 ) );
	printf("\n");

	treeRecursion(3);
	printf("\n");

	// Example for indirect recursion.
	indirectRecursionA(20);
	
	printf("\n%d", nestedRecursion(90));
	return 0;
}