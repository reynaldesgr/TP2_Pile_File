/**
 * @file file.c
 * @brief fichier d'implementation pour la gestion de file
 */
#include <stdlib.h>
#include <stdio.h>
#include "file.h"

/**  TO DO
 * @brief Initialiser une file du type eltType
 *   - allocation de memoire pour une structure file_t et un tableau de taille elements
 * @param [in] taille taille de la file
 * @return l'adresse de la structure file_t
 */
file_t * initFile(int t)
{
    file_t * f = NULL;

    if (t)
    {
        f = malloc(sizeof(file_t));

        f->base = (eltType *) malloc(t * sizeof(eltType));

        f->nbElts = 0;
        f->taille = t;

        f->deb  = f->base;
        f->fin  = f->base + f->taille -1;
        
    }

    return f;
}



/**  TO DO
 * @brief Verifier si la file est vide (aucun element dans la file)
 * @param [in] ptFile l'adresse de la structure file_t
 * @return 1 - vide, ou 0 - non vide
 */
int estVideFile(file_t * ptFile)
{
    return (ptFile->nbElts == 0) ? 1 : 0;
}


/** TO DO
 * @brief Verifier si la file est pleine
 * @param [in] ptFile l'adresse de la structure file_t
 * @return 1 - pleine, ou 0 - pas pleine
 */
int estPleineFile(file_t * ptFile)
{
    return (ptFile->nbElts == ptFile->taille) ? 1 : 0;
}


/** TO DO
 * @brief Liberer les memoires occupees par la file
 * @param [in, out] adrPtFile l'adresse du pointeur de la structure file_t
 */
void libererFile(file_t ** adrPtFile)
{
    if (*adrPtFile)
    {
        free((*adrPtFile)->base);
        (*adrPtFile)->deb = NULL;
        (*adrPtFile)->fin = NULL;
        free(*adrPtFile);

        *adrPtFile = NULL;
    }
}


/** TO DO
 * @brief Entrer un element dans la file
 * @param [in] ptFile le pointeur de tete de la file
 * @param [in] ptVal l'adresse de la valeur a empiler
 * @param [out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void entrerFile(file_t * ptFile, eltType * ptVal, int * code)
{
    if (ptFile)
    {
        *code = 1;
        if (estVideFile(ptFile))
        {

            ptFile->base[ptFile->nbElts] = *ptVal;
            ptFile->fin = ptFile->base;
            ptFile->deb = ptFile->base;

            ptFile->nbElts+=1;

            
            *code = 0;
        }else{
            if (!estPleineFile(ptFile))
            {
                ptFile->base[ptFile->nbElts] = *ptVal;
                ptFile->fin = &ptFile->base[ptFile->nbElts];
                
                ptFile->nbElts+=1;

                *code = 0;
            }
        }
    }
}


/** TO DO
 * @brief Sortir un element de la file
 * @param [in] ptFile le pointeur de tete d'une file
 * @param [out] ptRes l'adresse de l'element sorti
 * @param [out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void sortirFile(file_t * ptFile, eltType * ptRes, int * code)
{
    if (ptFile)
    {
        *code = 1;
        int t = ptFile->taille;
        if (estVideFile(ptFile) == 0)
        {

            *ptRes = *ptFile->deb;
            ptFile->nbElts-=1;

            if(ptFile->base + t == ptFile->deb + 1){
                ptFile->deb = ptFile->base;
            }else{
                ptFile->deb = ptFile->deb + 1;
            }
            *code = 0;
        }
        
    }
}
