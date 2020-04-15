#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
enum Comparison{LESS, EQUAL, GREATER};
class ItemType{
 public:
  ItemType();
  void print();
  void initialize(int number);
  Comparison compareTo(ItemType item);
  int getValue() const; //returns the value instance variable
 private:
  int value;
};
#endif
