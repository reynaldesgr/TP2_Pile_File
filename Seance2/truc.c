/**
 * @file truc.c
 * @brief fichier d'implementation du module de derecursification de la fonction truc (donne la liste de combinaisons de n elements)
 */
#include <stdio.h>
#include <stdlib.h> 

#include "../pile.h"

/** TO DO
 * @brief initialiser n caracteres dans un tableau de l'indice deb a l'indice fin
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in, out] T : un tableau de caracteres
 */
void initTab(int deb, int fin, char * T)
{
    int i;

    for (i = deb; i <= fin; i++)
    {
        T[i] = (65 + i - 1);
    }
}

/** TO DO
 * @brief afficher les caracteres d'un tableau de l'indice deb a l'indice fin a l'ecran
 * @param [in] deb l'indice du 1er caractere
 * @param [in] fin l'indice du dernier caractere
 * @param [in] T : un tableau de caracteres
*/
void printTab(int deb, int fin, char T[])
{
    int i;
    
    for (i = deb; i < fin; i++)
    {
        printf("->%c  ", T[i]);
    }

    printf("\n");
}

/** TO DO
 * @brief echanger les valeurs de 2 variables de type caractere
 * @param [in, out] a l'adresse de la 1ere variable 
 * @param [in, out] b l'adresse de la 2eme variable 
 */
void echangerChar(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/** TO DO
 * @brief l'algorithme recursive
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n caractere de l'indice 1 a l'indice n 
 */
void truc_rec(int i, int n, char * T)
{
    int j;

    if (i == n)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%c ", T[j]);
        }
        printf("\n");
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            echangerChar(&T[i], &T[j]);
            truc_rec(i + 1, n, T);
            echangerChar(&T[i], &T[j]);
        }
    }
}

/** TO DO
 * @brief l'algorithme iterative
 * @param [in] i l'indice du 1er element (i=1 avec ce TP)
 * @param [in] n l'indice du dernier element 
 * @param [in] T tableau de n+1 caracteres de l'indice 0 a l'indice n 
 */
void truc_iter(int i, int n, char * T)
{
    eltType    i_iter = {65 + i - 1, i};
    int    stop       = 0;
    int    code;
    eltType   j;

    // Initialisation de la pile & de j
    pile_t * p        = initPile(PILE_SZ);
    j.num = i_iter.num;

    // Début itération
    while(!stop)
    {
        if(j.num  <= n)
        {
            while (i_iter.num != n){
                empiler(p, &i_iter, &code);
                empiler(p, &j, &code);

                echangerChar(&T[i_iter.num], &T[j.num]);
                i_iter.num+=1;
                j.num = i_iter.num;
            }
            for (int k = 1; k <= n; k++)
            {
                printf("%c ", T[k]);
            }
            printf("\n");
        }

        // Test: Pile vide
        if (!estVidePile(p))
        {
            depiler(p, &j, &code);
            depiler(p, &i_iter, &code);

            echangerChar(&T[i_iter.num], &T[j.num]);
            j.num+=1;   
        }else{
            stop = 1;
        }
    }

    libererPile(&p);
}