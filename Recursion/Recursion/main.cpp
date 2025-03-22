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

	treeRecursion(4);
	return 0;
}