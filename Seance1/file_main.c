/**
 * program for general linked list testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../file.h"
#include "../teZZt.h"

BEGIN_TEST_GROUP(File)

TEST(SDD_File) {     // tester la taille de la structure file_t
	int     size_SDD = sizeof(int) + sizeof(int) + 3*sizeof(eltType *);
	file_t *file;

	printf("\nTest SDD_File : \n");
	CHECK( sizeof(*file) == size_SDD ); 
}


TEST(init_libererFile0) {   // tester la creation d'une file de taille 0
	file_t *file = NULL;

	printf("\nTest init_libererfile0 : \n");
	file = initFile(0);
	CHECK( NULL == file ); 

	libererFile(&file);     // tentative de liberation de memoire avec un pointeur null
	CHECK( NULL == file ); 
}


TEST(init_libererFile50) {  // tester la creation d'une file de taille !0
	file_t *file = NULL;
	int     taille = 50;

	printf("\nTest init_libererFile50 : \n");
	file = initFile(taille);
	REQUIRE( NULL != file ); 
	CHECK( NULL != file->base ); 

	CHECK( taille == file->taille );  // check tous les champs de la structure file
	CHECK( 0 == file->nbElts );
	CHECK( file->base == file->deb );
	CHECK( file->base+taille-1 == file->fin );

	libererFile(&file);     // tester la liberation de memoire 
	CHECK( NULL == file ); 

}

TEST(estVideFile) {        // tester la fonction estVideFile
	file_t *file = NULL;

	printf("\nTest estVideFile : \n");
	file = initFile(50);
	REQUIRE( NULL != file ); 

	CHECK( 1 == estVideFile(file) );  // file vide

	file->nbElts++;
	CHECK( 0 == estVideFile(file) );  // file non vide

	libererFile(&file);
	CHECK( NULL == file ); 
}

TEST(estPleineFile) {     // tester la fonction estPleineFile
	file_t *file = NULL;

	printf("\nTest estPleineFile : \n");
	file = initFile(50);
	REQUIRE( NULL != file ); 

	CHECK( 0 == estPleineFile(file) );  // file pas pleine

	file->nbElts += 50;
	CHECK( 1 == estPleineFile(file) );  // file pleine

	libererFile(&file);
	CHECK( NULL == file ); 
}

TEST(enfilerDefiler1) {   // tester l'enfilement/le defilement d'1 element
	file_t *file = NULL;
	int     taille = 50;  // taille de la file
	int     code = -1;
	// eltType elt, elt1=10;       // eltType int
	eltType elt, elt1={'A', 1}; // eltType struct

	printf("\nTest enfilerDefiler1 : \n");
	file = initFile(taille);
	REQUIRE( NULL != file ); 

	entrerFile(file, &elt1, &code);
	CHECK( 0 == estVideFile(file) );
	CHECK( taille == file->taille );
	CHECK( 1 == file->nbElts );
	CHECK( file->base == file->deb );    // une valeur dans la file : deb et fin sont sur la 1ere valeur
	CHECK( file->base == file->fin );
	CHECK( 1 == compareElt(&elt1, file->fin) );
	CHECK( 0 == code );

	sortirFile(file, &elt, &code);
	CHECK( 1 == compareElt(&elt, &elt1) );
	CHECK( 0 == code );

	sortirFile(file, &elt, &code);  // defilement impossible
	CHECK( 1 == code );

	libererFile(&file);
	CHECK( NULL == file ); 
}


TEST(enfilerDefiler2) {    // tester l'enfilement/le defilement de 2 elements
	file_t *file = NULL;
	int     taille = 50;
	int     code = -1;
//	eltType elt, elt1=10, elt2=20;    // eltType int
	eltType elt, elt1={'A', 1}, elt2={'B', 2};  // eltType struct

	printf("\nTest enfilerDefiler2 : \n");
	file = initFile(taille);
	REQUIRE( NULL != file ); 

	entrerFile(file, &elt1, &code);        // enfiler la 1ere valeur 10
	CHECK( 0 == estVideFile(file) );
	CHECK( taille == file->taille );
	CHECK( 1 == file->nbElts );
	CHECK( file->base == file->deb );   // 1 valeur dans la file : deb et fin sont sur la 1ere valeur
	CHECK( file->base == file->fin );
	CHECK( 1 == compareElt(&elt1, file->fin) );
	CHECK( 0 == code );

	entrerFile(file, &elt2, &code);        // enfiler la 2eme valeur 20
	CHECK( 0 == estVideFile(file) );
	CHECK( 2 == file->nbElts );
	CHECK( file->base == file->deb );     // 2 valeurs dans la file : deb est sur la 1ere valeur
	CHECK( file->base + 1 == file->fin ); // fin est sur la 2eme valeur
	CHECK( 1 == compareElt(&elt2, file->fin) );
	CHECK( 0 == code );

	sortirFile(file, &elt, &code);      // defiler la 1ere valeur {'A', 1}
	CHECK( 1 == file->nbElts );
	CHECK( 1 == compareElt(&elt, &elt1) );
	CHECK( 0 == code );
	CHECK( file->base + 1 == file->deb ); // 1ere valeur est sortie de la file : deb est sur la 2eme valeur
	CHECK( file->base + 1 == file->fin ); // fin est sur la 2eme valeur


	sortirFile(file, &elt, &code);      // defiler la 2eme valeur {'B', 2}
	CHECK( 0 == file->nbElts );
	CHECK( 1 == compareElt(&elt, &elt2) );
	CHECK( 0 == code );
	CHECK( file->fin < file->deb ); // 0 valeur dans la file : deb > fin

	sortirFile(file, &elt, &code);  // defilement impossible
	CHECK( 1 == code );

	libererFile(&file);
	CHECK( NULL == file ); 
}

TEST(enfilerDefilerTaille) {    // tester l'enfilement/le defilement d'une file pleine
	file_t *file = NULL;
	int taille = 26, i = 0;
	int code = -1;
	eltType elt, tmp;

	printf("\nTest enfilerDefilerTaille : \n");
	file = initFile(taille);
	REQUIRE( NULL != file ); 

	CHECK( taille == file->taille );
	CHECK( file->base == file->deb );

	// tests emfilement possibles
	for (i=1; i<=taille; i++)  // remplir la file de 26 structures de {'A',1} a {'Z',26}
	{
		//elt = i*10;             // eltType int
		elt.lettre = 'A' + i-1; // eltType struct
		elt.num = i;

		entrerFile(file, &elt, &code);
		CHECK( 0 == estVideFile(file) );
		CHECK( i == file->nbElts );   
		CHECK( file->base + i-1 == file->fin );
		CHECK( 1 == compareElt(&elt, file->fin) );
		CHECK( 0 == code );	
	}

	// test enfilement impossible
	entrerFile(file, &elt, &code);
	CHECK( 1 == code );
	CHECK( 1 == estPleineFile(file) );

	// tests defilement possibles
	for (i=1; i<taille; i++)
	{
		sortirFile(file, &elt, &code);
		CHECK( 0 == code );
//		tmp = i*10;            // eltType int
		tmp.lettre = 'A'+i-1;  // eltType struct
		tmp.num = i;
		CHECK( 1 == compareElt(&tmp, &elt) );
		CHECK( taille - i == file->nbElts );
		CHECK( file->base + i == file->deb );
	}
		// derniere valeur i==taille
		sortirFile(file, &elt, &code);
		CHECK( 0 == code );
// 		tmp = i*10;           // eltType int
		tmp.lettre = 'A' + taille - 1; // eltType struct
		tmp.num = taille;
		CHECK( 1 == compareElt(&tmp, &elt) );
		CHECK( taille - i == file->nbElts );
		CHECK( file->base == file->deb );

	// test defilement impossible
	sortirFile(file, &elt, &code);
	CHECK( 1 == code );
	CHECK( 1 == estVideFile(file) );

	libererFile(&file);
	CHECK( NULL == file ); 
}

END_TEST_GROUP(File)

int main(void) {
	RUN_TEST_GROUP(File);
	return EXIT_SUCCESS;
}
