/**
 * program for general linked list testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../eltType.h"
#include "../pile.h"
#include "../teZZt.h"

BEGIN_TEST_GROUP(Pile)

TEST(SDD_Pile) {  // tester la taille de la structure pile_t
	int     size_SDD = sizeof(int) + sizeof(int) + sizeof(eltType *);
	pile_t *pile;

	printf("\nTest SDD_Pile : \n");
	CHECK( sizeof(*pile) == size_SDD ); 
}


TEST(init_libererPile0) {   // tester la creation d'une pile de taille 0
	pile_t *pile = NULL;

	printf("\nTest init_libererPile0 : \n");
	pile = initPile(0);
	CHECK( NULL == pile ); 

	libererPile(&pile);     // tentative de liberation de memoire avec un pointeur null
	CHECK( NULL == pile ); 
}

TEST(init_libererPile50) {  // tester la creation d'une pile de taille != 0
	pile_t *pile = NULL;

	printf("\nTest init_libererPile50 : \n");
	pile = initPile(50);
	REQUIRE( NULL != pile ); 

	CHECK( 50 == pile->taille );
	CHECK( -1 == pile->sommet );
	CHECK( NULL != pile->base );
	libererPile(&pile);     // tester la liberation de memoire 
	CHECK( NULL == pile ); 
}

TEST(estVidePile) {   // tester la fonction estVidePile
	pile_t *pile = NULL;

	printf("\nTest estVidePile : \n");
	pile = initPile(50);
	REQUIRE( NULL != pile ); 

	CHECK( 1 == estVidePile(pile) );  // Pile vide

	pile->sommet++;
	CHECK( 0 == estVidePile(pile) );  // Pile non vide

	libererPile(&pile);
	CHECK( NULL == pile ); 
}


TEST(empilerDepiler1) {   // tester les fonctions empiler/depiler d'1 element
	pile_t *pile = NULL;
	int     code = -1;
	// eltType elt, elt1 = 10;       // eltType int
	eltType elt, elt1 = {'A', 1}; // eltType struct

	printf("\nTest empilerDepiler1 : \n");
	pile = initPile(50);
	REQUIRE( NULL != pile ); 

	empiler(pile, &elt1, &code);
	CHECK( 0 == estVidePile(pile) );
	CHECK( 50 == pile->taille );
	CHECK( 0 == pile->sommet );
	CHECK( 1 == compareElt(&elt1, pile->base + pile->sommet) );
	CHECK( 0 == code );

	depiler(pile, &elt, &code);
	CHECK( 1 == compareElt(&elt1, &elt) );
	CHECK( 0 == code );

	depiler(pile, &elt, &code);  // depilement impossible
	CHECK( 1 == code );

	libererPile(&pile);
	CHECK( NULL == pile ); 
}

TEST(empilerDepiler2) { // tester les fonctions empiler/depiler de 2 elements
	pile_t *pile = NULL;
	int     code = -1;
//	eltType elt, elt1 = 10, elt2 = 20;  // eltType int
	eltType elt, elt1 = {'A', 1}, elt2 = {'B', 2}; // eltType struct

	printf("\nTest empilerDepiler2 : \n");
	pile = initPile(50);
	REQUIRE( NULL != pile ); 

	empiler(pile, &elt1, &code);
	CHECK( 0 == estVidePile(pile) );
	CHECK( 50 == pile->taille );
	CHECK( 0 == pile->sommet );
	CHECK( 1 == compareElt(&elt1, pile->base + pile->sommet) );
	CHECK( 0 == code );

	empiler(pile, &elt2, &code);
	CHECK( 0 == estVidePile(pile) );
	CHECK( 50 == pile->taille );
	CHECK( 1 == pile->sommet );
	CHECK( 1 == compareElt(&elt2, pile->base + pile->sommet) );
	CHECK( 0 == code );

	depiler(pile, &elt, &code);
	CHECK( 1 == compareElt(&elt2, &elt) );
	CHECK( 0 == code );

	depiler(pile, &elt, &code);
	CHECK( 1 == compareElt(&elt1, &elt) );
	CHECK( 0 == code );

	depiler(pile, &elt, &code);  // depilement impossible
	CHECK( 1 == code );

	libererPile(&pile);
	CHECK( NULL == pile ); 
}

TEST(empilerDepilerTaille) {  // tester les fonctions empiler/depiler de taille elements
	pile_t *pile = NULL;
	int taille = 26, i = 0;
	int code = -1;
	eltType elt;

	printf("\nTest empilerDepilerTaille : \n");
	pile = initPile(taille);
	REQUIRE( NULL != pile ); 

	// tests empilement possibles
	for (i=0; i<taille; i++)
	{
//		elt = i;              // eltType int
		elt.lettre = 'A' + i; // eltType struct
		elt.num = i + 1;

		empiler(pile, &elt, &code);
		CHECK( 0 == estVidePile(pile) );
		CHECK( taille == pile->taille );
		CHECK( i == pile->sommet );
		CHECK( 1 == compareElt(&elt, pile->base + pile->sommet) );
		CHECK( 0 == code );
	}

	// test empilement impossible
//	elt = 100;              // eltType int
	elt.num = 100;          // eltType struct
	empiler(pile, &elt, &code);
	CHECK( 1 == code );
	CHECK( taille == pile->taille );
	CHECK( taille-1 == pile->sommet );
	CHECK( 0 == compareElt(&elt, pile->base + pile->sommet) );

	// tests depilement possibles
	for (i=0; i<taille; i++)
	{
		depiler(pile, &elt, &code);
		CHECK( 0 == code );
		CHECK( 1 == compareElt(&elt, pile->base + pile->sommet + 1) );
		CHECK( taille-2-i == pile->sommet );
	}

	// test depilement impossible
	depiler(pile, &elt, &code);
	CHECK( 1 == code );

	libererPile(&pile);
	CHECK( NULL == pile ); 
}

END_TEST_GROUP(Pile)

int main(void) {
	RUN_TEST_GROUP(Pile);
	return EXIT_SUCCESS;
}
