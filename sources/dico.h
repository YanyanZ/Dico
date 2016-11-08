/**
 * \file dico.h
 * \brief Contient la définition du dico et des fonctions utiles.
 * \author Florian.T
 * \version 0.1
 * \date 8 Novembre 2016
 *
 * Programme de test.
 *
 */

#ifndef __DICO_H__
# define __DICO_H__

# include <stdlib.h>
# include <stdio.h>

typedef struct Node
{
  size_t   nbChild;
  char     value;
  int      endWord;
  struct Node** pChildren;
} s_Node;

int addWord(s_Node* tree, char* word, size_t wSize);
int findWordApprox(const s_Node* tree, char*, size_t wSize);

#endif /*__DICO_H__ */
