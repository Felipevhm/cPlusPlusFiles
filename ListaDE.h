#ifndef LISTADE
#define LISTADE

#include "Node.cpp"



class ListaDE {
  Node* head;
  public:

  ListaDE();
  ListaDE(Node * n);
  Node* gethead();
  void sethead(Node* newhead);
  Node * nodeExists(int k);
  void addNodo(Node * n);
  void addNodofim(Node * n);
  void addNodoapos(int k, Node * n);
  void delNodoByKey(int k);
  void updateNodoByKey(int k, int d);
  
  void printList();
  

 
};

#endif
