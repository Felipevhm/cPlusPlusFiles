// ListaDE.cpp

#ifndef LISTADECPP
#define LISTADECPP

#include "ListaDE.h"
#include <iostream>
using namespace std;


ListaDE::ListaDE() {
    head = NULL;
   
  }
ListaDE::ListaDE(Node * n) {
    head = n;
    
  }
Node*  ListaDE::gethead(){
  	return head; 	
  };
void ListaDE::sethead(Node* newhead){
  	head=newhead;  	
  };
 
 
Node* ListaDE::nodeExists(int k) {
Node* temp = NULL;
Node* ptr = gethead();
 
while (ptr!= NULL) {
      if (ptr->getkey() == k) {
        temp = ptr;
      }
      ptr=ptr->getnext();
    }
 
    return temp;
  }
 

 
void ListaDE::addNodo(Node * n) {
    if (nodeExists(n->getkey()) != NULL) {
      cout << "Nodo existente com key : " << n->getkey() << ". Adicione um nodo com key distinto" << endl;
    } else {
      if (gethead() == NULL) {
        sethead(n);
        
       // cout << "Nodo adicionado como 'Head' " << endl;
      } else {
        Node*ptr = gethead();
        while (ptr->getnext() != NULL) {
          ptr = ptr->getnext();
        }
        ptr->setnext(n);
        n->setprev(ptr);
        cout << "Nodo Adicionado" << endl;
      }
    }
  }
  
  

 
void ListaDE::addNodofim(Node * n) {
    if (nodeExists(n->getkey()) != NULL) {
      cout << "Nodo existente com a chave:" << n->getkey() << ". Adicione um nodo com chave distinta" << endl;
    } else {
      if (gethead() == NULL) {
        sethead(n);
        cout << "Nodo adicionado no inicio" << endl;
      } else {
        head->setprev(n);
        n->setnext(head);
        sethead(n);
        cout << "Node adicionado no inicio" << endl;
      }
 
    }
  }
  
  
  
void ListaDE::addNodoapos(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "Nodo inexistente com essa key : " << k << endl;
    } else {
      if (nodeExists(n->getkey()) != NULL) {
        cout << "Nodo ja existe com essa key : " << n->getkey() << ". Adicione um nodo com chave distinta" << endl;
      } else {
        Node * nextNode = ptr->getnext();
    
        if (nextNode == NULL) {
          ptr->setnext(n);
          n->setprev(ptr);
          cout << "Nodo inserido no fim" << endl;
        }

        else {
          n->setnext(nextNode);
          nextNode->setprev(n);
          n->setprev(ptr);
          ptr->setnext(n);
 
          cout << "Nodo inserido no meio" << endl;
 
        }
 
      }
    }
  }
  
  
   
void ListaDE::delNodoByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "Nodo com o valor: " << k <<"inexistente"<<endl;
    } else {
 
      if (head->getkey() == k) {
        head = head->getnext();
        delete ptr;
        cout << "Nodo com o key:" << k << " deletado."<< endl;
      } else {
        Node * nextNode = ptr->getnext();
        Node * prevNode = ptr->getprev();
        // deleting at the end
        if (nextNode == NULL) {
 
          prevNode->setnext(NULL);
          delete ptr;
          cout << "Nodo deletado no fim da lista" << endl;
        }
 
        //deleting in between
        else {
          prevNode->setnext(nextNode);
          nextNode->setprev(prevNode);
          delete ptr;
          cout << "Nodo deletado no fim" << endl;
 
        }
      }
    }
  }
  
   
 
// 6th update node
void ListaDE::updateNodoByKey(int k, int d) {
 
	Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr->setdata(d);
      cout << "Update do nodo realizado" << endl;
    } 
	else {
      cout << "Nodo inexistente com essa key : " << k << endl;
    }
 
}
  
  
 
  // 7th printing
void ListaDE::printList() {
    if (gethead() == NULL) {
      cout << "Lista Vazia";
    } 
	else {
      cout << endl << "Valores da lista duplamente encadeada : \n\n";
      
      Node* temp = gethead();
 
      while (temp != NULL) {
        cout << "(" << temp->getkey()<< "," <<temp->getstr()<<")\n<-->\n";
        temp = temp->getnext();
      }
    }
 
}
  #endif
  /*
  int main(){
  	int b=3;
  	ListaDE lde;
 	Node*  th=new Node(b,"sem nome 1");
	lde.addNodo(th);
	
	Node*  th2=new Node(b*2,"sem nome 2");
	lde.addNodo(th2);
	
	lde.printList();

  	
  	return 0;
  }
  */
  
