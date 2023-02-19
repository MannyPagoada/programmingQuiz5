//
// Created by manuelpagoada on 2/18/23.
//

#ifndef PROGRAMMINGQUIZ5_ITEMTYPE_H
#define PROGRAMMINGQUIZ5_ITEMTYPE_H


#include <fstream>
const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
private:
  int value;
};

#endif //PROGRAMMINGQUIZ5_ITEMTYPE_H
