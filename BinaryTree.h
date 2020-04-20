#ifndef BINARYTREE_H
#define  BINARYTREE_H
#include <iostream>
#include "ItemType.h"

const int MAX_ITEM=5 ;
  struct Node{
    ItemType key;
    Node *left;
    Node *right;
  };

class BinaryTree{
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
    //int CountNodes(Node* tree);
    void getSameLevelNonsiblings(ItemType &key);    
//    int findLevel(ItemType& item, Node*& tree, int level);
//    void printSameLevelNonSiblings(Node*& tree, ItemType& item, int level, bool &found);
    
private:
  Node *root;
};
#endif
