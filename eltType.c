/**
 * @file eltType.c
 * @brief fichier d'implementation pour la gestion du type des elements
 *        Ce module contient le type de donnees et les fonctions de gestion de piles/file
 *        L'utilisant du type 'eltType' permet aux piles/files de stocker des elements de different type
 */
#include <stdio.h>
#include "eltType.h"

/* ------------------------- Gestion des elements de type 'int' ------------------------- */
/** TO DO
 * @brief Ecrire une fonction de comparaison de 2 elements 'int'
 * @param [in] xxx l'adresse du 1er element du type 'eltType'
 * @param [in] xxx l'adresse du 2eme element du type 'eltType'
 * @return 1 si les 2 elements sont egaux; 0 s'ils sont differents
 */


/** TO DO
 * @brief Copier la valeur d'un element a un autre emplacement
 * @param [in] xxx l'adresse de l'element a copier
 * @param [in] xxx l'adresse de la destination
 */
// copyElt()
// {
// 	// TO DO
// }



/* ---------- Gestion des elements de type struct contenant un 'char' et un 'int' ---------- */
/** TO DO
 * @brief Ecrire une fonction de comparaison de 2 elements
 * @param [in] xxx l'adresse du 1er element
 * @param [in] xxx l'adresse du 2eme element
 * @return 1 si les 2 elements sont egaux; 0 s'ils sont differents
 */
int compareElt(eltType * e1, eltType * e2)
{
    int r = 0;
    if (e1->num == e2->num && e1->lettre == e2->lettre)
    {
        r = 1;
    }

    return r;
}

// /** TO DO
//  * @brief Copier la valeur d'un element dans un autre emplacement
//  * @param [in] xxx l'adresse de l'element a copier
//  * @param [in] xxx l'adresse de la destination
//  */
void copyElt(eltType * source, eltType * destination)
{
    if (source && destination)
    {
        destination->num = source->num;
        destination->lettre = source->lettre;
    }
}
