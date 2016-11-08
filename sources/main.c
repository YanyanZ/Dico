/**
 * \file main.c
 * \brief Programme de tests.
 * \author Florian.T
 * \version 0.1
 * \date 8 Novembre 2016
 *
 * Programme de test.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "dico.h"

/**
 * \fn int main(void)
 * \brief Entrée du programme.
 */
int main(void)
{
  printf("Lancement\n");

  s_Node* tree = (s_Node*)malloc(sizeof(s_Node));
  if (tree == NULL)
    return 1;

  tree->nbChild = 0;

  addWord(tree, "test", 4);
  printf("> Tree size : %lu - Nb child : %lu\n", sizeof(tree), tree->nbChild);
  
  addWord(tree, "toto", 4);
  printf("> Tree size : %lu - Nb child : %lu\n", sizeof(tree), tree->nbChild);

  addWord(tree, "aoto", 4);
  printf("> Tree size : %lu - Nb child : %lu\n", sizeof(tree), tree->nbChild);

  printf("Search word '%s' -> ", "to");
  if (findWordApprox(tree, "to", 2) == 0)
    printf(" Exact word found");
  else
    printf(" Exact word not found");  
  printf("\n");

  printf("Search word '%s' -> ", "toto");
  if (findWordApprox(tree, "toto", 5) == 0)
    printf(" Exact word found");
  else
    printf(" Exact word not found");  
  printf("\n");

  printf("Search word '%s' -> ", "ao");
  if (findWordApprox(tree, "ao", 2) == 0)
    printf(" Exact word found");
  else
    printf(" Exact word not found");  
  printf("\n");

    printf("Search word '%s' -> ", "aoto");
  if (findWordApprox(tree, "aoto", 4) == 0)
    printf(" Exact word found");
  else
    printf(" Exact word not found");  
  printf("\n");

  
  free(tree);

  return EXIT_SUCCESS;
}
