#ifndef LT_H
#define LT_H

#include "Td.cpp"



class Lt {
  Td* head;
  public:

  Lt();
  Lt(Td * n);
  Td* gethead();
  void sethead(Td* newhead);
  Td * nodeExists(int k);
  void addNodo(Td * n);
  void addNodofim(Td * n);
  void addNodoapos(int k, Td * n);
  void delNodoByKey(int k);
  void updateNodoByKey(int k, int d);
  
  void printList();
  

 
};

#endif
