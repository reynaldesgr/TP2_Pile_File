/**
 * program for general linked list testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pile.h"
#include "truc.h"
#include "../teZZt.h"


BEGIN_TEST_GROUP(TRUC)

TEST(Pile_SDD) {
	int size_SDD = 2*sizeof(int) + sizeof(eltType *);
	pile_t *pile;

	CHECK( sizeof(*pile) == size_SDD ); 
}

/*
TEST(truc_rec13) {
	int n=3;
	char T[n+1];

	printf("\033[34m\ntruc_rec(1, 3, T) :");
	printf("\033[0m\n");
	initTab(1, n, T);
	CHECK( 'A' == T[1] ); 
	CHECK( 'B' == T[2] );
 	CHECK( 'C' == T[3] ); 

	printf("\033[34m");
	truc_rec(1, 3, T);
	printf("\033[0m\n");
}


TEST(truc_rec14) {
	int n=4;
	char T[n+1];

	printf("\033[34mtruc_rec(1, 4, T) :");
	printf("\033[0m\n");
	initTab(1, n, T);
	CHECK( 'A' == T[1] ); 
	CHECK( 'B' == T[2] );
 	CHECK( 'C' == T[3] ); 
 	CHECK( 'D' == T[4] ); 

	printf("\033[34m");
	truc_rec(1, 4, T);
	printf("\033[0m\n");
}


TEST(truc_iter13) {
	int n=3;
	char T[n+1];

	printf("\033[34m\ntruc_iter(1, 3, T) :");
	printf("\033[0m\n");
	initTab(1, n, T);
	CHECK( 'A' == T[1] ); 
	CHECK( 'B' == T[2] );
 	CHECK( 'C' == T[3] ); 

	printf("\033[34m");
	truc_iter(1, 3, T);
	printf("\033[0m\n");
}

TEST(truc_iter14) {
	int n=3;
	char T[n+1];

	printf("\033[34m\ntruc_iter(1, 4, T) :");
	printf("\033[0m\n");
	initTab(1, n, T);
	CHECK( 'A' == T[1] ); 
	CHECK( 'B' == T[2] );
 	CHECK( 'C' == T[3] ); 
 	CHECK( 'D' == T[4] ); 

	printf("\033[34m");
	truc_iter(1, 4, T);
	printf("\033[0m\n");
}
*/
END_TEST_GROUP(TRUC)

int main(void) {
	RUN_TEST_GROUP(TRUC);
	return EXIT_SUCCESS;
}
