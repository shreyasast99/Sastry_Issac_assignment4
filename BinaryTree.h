#ifndef BINARYTREE_H
#define  BINARYTREE_H
#include <iostream>
#include "ItemType.h"

const int MAX_ITEM=5 ;
  struct Node{
    ItemType key;
    Node *left;
    Node *right
    
  };

class CircularLinkedList{
public:
  BinaryTree();
  ~BinaryTree();
  void insert(ItemType key);
  void deleteItem(ItemType key);
  void retrieve(ItemType &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  void getSameLevelNonsiblings(ItemType &key);
  
private:
  Node *root;
};
#endif
