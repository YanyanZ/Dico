#include "dico.h"

int addWord(s_Node* tree, char* word, size_t wSize)
{
  if (tree == NULL)
    return 1;

  if (word == NULL || wSize == 0) {
    tree->endWord = 1;
    return 1;
  }

  s_Node* node = NULL;
  for (size_t i = 0; i < tree->nbChild; ++i) {
    if (tree->pChildren[i]->value == word[0]) {
      node = tree->pChildren[i];
      break;
    }
  }

  if (node == NULL) {
    node = (s_Node*)malloc(sizeof(s_Node));
    if (node == NULL)
      return 1;

    node->nbChild = 0;
    node->value = word[0];
    
    tree->nbChild++;
    if (tree->pChildren == NULL)
      tree->pChildren = (s_Node**)malloc(sizeof(s_Node*));
    tree->pChildren = (s_Node**)realloc(tree->pChildren, tree->nbChild * sizeof(s_Node*));
    tree->pChildren[tree->nbChild - 1] = node;
  }

  char* subWord = (word + 1);
  wSize--;
  
  addWord(node, subWord, wSize);
  
  return 0;
}

int findWordApprox(const s_Node* tree, char* word, size_t wSize) {
  if (tree == NULL) {
    return 1;
  }

  if (word == NULL || wSize == 0) {
    if (tree->endWord == 1)
      return 0;
    return 1;
  }
  
  s_Node* nextNode = NULL;
  for (size_t i = 0; i < tree->nbChild; ++i) {
    if (tree->pChildren[i]->value == word[0]) {
      nextNode = tree->pChildren[i];
    }
  }

  if (nextNode != NULL && wSize != 0)
    findWordApprox(nextNode, (word + 1), --wSize);

  return 1;
}
