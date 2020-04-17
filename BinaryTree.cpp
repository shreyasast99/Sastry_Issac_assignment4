#include "BinaryTree.h"
#include <string>
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(){
}
BinaryTree::~BinaryTree(){
}

void PutItem(Node*& tree, ItemType item);
void BinaryTree::insert(ItemType item)
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
  else if (item.compareTo(tree->key)==LESS)
    PutItem(tree->left, item); // Insert in left subtree.
  else
    PutItem(tree->right, item); // Insert in right subtr
}
void Delete(Node*&tree, ItemType item);
void DeleteNode(Node*& tree);
void GetPredecessor(Node* tree, ItemType& data);
void BinaryTree::deleteItem(ItemType key){
//THIS IS DELETE
    Delete(root,key); 
}
void Delete(Node*&tree, ItemType item){
    if (item.compareTo(tree->key)==LESS)
        Delete(tree->left, item);
    else if (item.compareTo(tree->key)==GREATER)
        Delete(tree->right, item);
    else
        DeleteNode(tree);  // Node found
}
void DeleteNode(Node*& tree){
    ItemType data;
    Node* tempPtr;
    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL){
        tree = tree->left;
        delete tempPtr;
    }else{
        GetPredecessor(tree->left, data);
        tree->key = data;
        Delete(tree->left, data);
    }
}
void GetPredecessor(Node* tree, ItemType& data){
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->key;
}
void getItem(Node* tree, ItemType& item, bool& found);
void BinaryTree::retrieve(ItemType &item, bool &found) const{
    getItem(root,item,found);
}
void getItem(Node* tree, ItemType& item, bool& found){
    if (tree == NULL)
        found = false; // item is not found.
    else if (item.compareTo(tree->key)==LESS)
        getItem(tree->left, item, found); // Search left subtree.
    else if (item.compareTo(tree->key)==GREATER)
        getItem(tree->right, item, found); // Search right subtree.
    else{
        item = tree->key; // item is found.found = true;
        found=true;
    }
}
void printPr(Node *tree);
void BinaryTree::preOrder() const{
    printPr(root);
}
void printPr(Node *tree){
    if (tree != NULL){
        cout << tree->key.getValue()<< " ";
        printPr(tree->left);
        printPr(tree->right);
    }
}
void printI(Node *tree);
void BinaryTree::inOrder() const{
    printI(root);
}
void printI(Node *tree){
    if (tree != NULL){
        printI(tree->left);
        cout << tree->key.getValue()<< " ";
        printI(tree->right);
    }
}
void printPo(Node *tree);
void BinaryTree::postOrder() const{
    printPo(root);
}
void printPo(Node *tree){
    if (tree != NULL){
        printPo(tree->left);
        printPo(tree->right);
        cout << tree->key.getValue()<<" ";
    }
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
