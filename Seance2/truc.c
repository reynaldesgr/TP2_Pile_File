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
        printf("%c  ", T[i]);
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
    eltType    n_iter = {65 + n - 1, n};
    int    stop   = 0;
    int    code;
    pile_t p;

    while (!stop)
    {
        if (i_iter.num == n_iter.num)
        {
            for (j = 1; j <= n_iter.num; j++)
            {
                printf("%c ", T[j]);
            }
            stop = 1;
        }else{
            while (i_iter.num != n_iter.num){
                empiler(p, i_iter, &code);
                empiler(p, n_iter, &code);
            }

            /** pas fini **/
        }
    }
}