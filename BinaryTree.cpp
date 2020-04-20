#include "BinaryTree.h"
#include <string>
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(){
}
//this method is used to get ride of memeory leaks
void destroyTree(Node*& node){
  if(node != NULL){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}
//the deconstructor
BinaryTree::~BinaryTree(){
    destroyTree(root);
}
//this is used to place the item into the list.
//we use this in the insert method
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
int findLevel(ItemType& item, Node*& tree, int level);
void Delete(Node*&tree, ItemType item);
void DeleteNode(Node*& tree);
void GetPredecessor(Node* tree, ItemType& data);
void printSameLevelNonsiblings(Node*& tree, ItemType& item, int level, bool &found);
void BinaryTree::deleteItem(ItemType key){
//this is the delete method
    Delete(root,key); 
}
//this method deletes the node within 
void Delete(Node*&tree, ItemType item){
    if (item.compareTo(tree->key)==LESS)
        Delete(tree->left, item);
    else if (item.compareTo(tree->key)==GREATER)
        Delete(tree->right, item);
    else
        DeleteNode(tree);  // Node found
}
//connected with the delete method
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
//this method returns the predecessor
void GetPredecessor(Node* tree, ItemType& data){
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->key;
}
//this method retrieves the getItem()
void getItem(Node* tree, ItemType& item, bool& found);
void BinaryTree::retrieve(ItemType &item, bool &found) const{
    getItem(root,item,found);
}
//this is used for the retrive function
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
//used to print the preorder of the tree
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
 
int findLevel(ItemType& item, Node*& tree, int level){
    if(tree == NULL){
        return 0;
    }
    if(tree->key.getValue() == item.getValue())
        return level;
    int traverseLevel = findLevel(item, tree->left, level+1);
    if(traverseLevel !=0)
        return traverseLevel;
    else
        return findLevel(item, tree->right, level+1);
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
    bool found = false;
    Node* node;
    int val2 = findLevel(key, root, 0);
    printSameLevelNonsiblings(root, key, val2+1, found);
    if(!found)
        cout << "No same level non siblings found" << endl;
}
void printSameLevelNonsiblings(Node*& tree, ItemType& item, int level, bool &found){
    if(level < 2 || tree == NULL){
        return;
    }
    if(level ==2){
        if(tree->left == NULL)
            return;
        if(tree->right == NULL)
            return;
        if(tree->left->key.getValue() == item.getValue() || tree->right->key.getValue() == item.getValue())
            return;
        if(tree->left != NULL && tree->left->key.getValue() != item.getValue()){
            cout << tree->left->key.getValue() << " ";
            found = true;
        }
        if(tree->right != NULL && tree->right->key.getValue() != item.getValue()){
            cout << tree->right->key.getValue() << " ";
            found=true;
        }
    }
    else if(level >2){
        printSameLevelNonsiblings(tree->left, item, level-1, found);
        printSameLevelNonsiblings(tree->right, item, level-1, found);
    }
}
