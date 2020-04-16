#include "BinaryTree.h"
#include <string>
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(){
}
BinaryTree::~BinaryTree(){
}

void PutItem(Node*& tree, ItemType item);
void BinaryTree::Insert(ItemType item)
{
  PutItem(root, item);
}
void PutItem(Node*& tree, ItemType item){
  if (tree == NULL)
  {// Insertion place found.
    tree = new Node;
    tree->right = NULL;
    tree->left = NULL;
    tree->key = item;
  }
  else if (item <tree->key)
    PutItem(tree->left, item); // Insert in left subtree.
  else
    PutItem(tree->right, item); // Insert in right subtr
}

void BinaryTree::deleteItem(ItemType key){
}
void BinaryTree::retrieve(ItemType &item, bool &found) const{
}
void BinaryTree::preOrder() const{
}
void BinaryTree::inOrder() const{
}
void BinaryTree::postOrder() const{
}
//used for getLength(). Created extra function CountNodes
int CountNodes(Node* tree);
int BinaryTree::getLength() const{
  return CountNodes(root);
}
int CountNodes(Node* tree){
  if(tree==NULL){
    return 0;
  }
  else{
    return CountNodes(tree->left)+ CountNodes(tree->right)+1;
  }
}
void BinaryTree::getSameLevelNonsiblings(ItemType &key){
}
