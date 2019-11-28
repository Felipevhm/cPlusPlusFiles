// ListaDE.cpp

#ifndef LT_CPP
#define LT_CPP

#include "Lt.h"
#include <iostream>
using namespace std;


Lt::Lt() {
    head = NULL;
   
  }
Lt::Lt(Td * n) {
    head = n;
    
  }
Td*  Lt::gethead(){
  	return head; 	
  };
void Lt::sethead(Td* newhead){
  	head=newhead;  	
  };
 
 
Td* Lt::nodeExists(int k) {
Td* temp = NULL;
Td* ptr = gethead();
 
while (ptr!= NULL) {
      if (ptr->getkey() == k) {
        temp = ptr;
      }
      ptr=ptr->getnext();
    }
 
    return temp;
  }
 

 
void Lt::addNodo(Td * n) {
    if (nodeExists(n->getkey()) != NULL) {
      cout << "Nodo existente com key : " << n->getkey() << ". Adicione um nodo com key distinto" << endl;
    } else {
      if (gethead() == NULL) {
        sethead(n);
        
       // cout << "Nodo adicionado como 'Head' " << endl;
      } else {
        Td*ptr = gethead();
        while (ptr->getnext() != NULL) {
          ptr = ptr->getnext();
        }
        ptr->setnext(n);
        n->setprev(ptr);
     //   cout << "Nodo Adicionado" << endl;
      }
    }
  }
  
  

 
void Lt::addNodofim(Td * n) {
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
        cout << "Td adicionado no inicio" << endl;
      }
 
    }
  }
  
  
  
void Lt::addNodoapos(int k, Td * n) {
    Td * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "Nodo inexistente com essa key : " << k << endl;
    } else {
      if (nodeExists(n->getkey()) != NULL) {
        cout << "Nodo ja existe com essa key : " << n->getkey() << ". Adicione um nodo com chave distinta" << endl;
      } else {
        Td * nextNode = ptr->getnext();
    
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
  
  
   
void Lt::delNodoByKey(int k) {
    Td * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "Nodo com o valor: " << k <<"inexistente"<<endl;
    } else {
 
      if (head->getkey() == k) {
        head = head->getnext();
        delete ptr;
        cout << "Nodo com o key:" << k << " deletado."<< endl;
      } else {
        Td * nextNode = ptr->getnext();
        Td * prevNode = ptr->getprev();
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
void Lt::updateNodoByKey(int k, int d) {
 
	Td * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr->setdata(d);
      //cout << "Update do nodo realizado" << endl;
    } 
	else {
      cout << "Nodo inexistente com essa key : " << k << endl;
    }
 
}
  
  
 
  // 7th printing
void Lt::printList() {
    if (gethead() == NULL) {
      cout << "Lista Vazia";
    } 
	else {
      cout << endl << "Valores da lista duplamente encadeada : \n\n";
      
      Td* temp = gethead();
 
      while (temp != NULL) {
        cout << "(" << temp->getkey()<< "," <<temp->getthreadname()<<")\n<-->\n";
        temp = temp->getnext();
      }
    }
 
}
  #endif
  /*
    int main(){
  	int b=3;
  	Lt lt;
 	Td*  th=new Td(b,"sem nome 1");
	lt.addNodo(th);
	
	Td*  th2=new Td(b*2,"sem nome 2");
	lt.addNodo(th2);
	
	lt.printList();

  	
  	return 0;
  }
  */
  
  
  
