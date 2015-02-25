#include <iostream>
#include <string>
#include "list.h"
#include"node.h"
class List {
public:
    List() {
        head = NULL;
        tail = NULL;
    }		
    void push_front(T element) {
		Node<T> * node = new Node<T>(element);
		if (head != NULL){//not first on list
		head->prev= node;
		node->next = head;
        head = node;
		node->prev =NULL;
		}
		if (tail==NULL){// first in list
		head=node;
		tail=node;
		}
    }
    T peek_front() {
        return head->data;
    }
    void pop_front() {
		Node<T> * node = head->next;
		delete head;
		head = node;
		if (node!=NULL){
		node->prev=NULL;
		}
		else{
			tail=NULL;
		}
    }
    void push_back(T element) {
		Node<T> * node = new Node<T>(element);
		if (tail != NULL){//not first on list
		tail->next= node;
		node->prev = tail;
		tail = node;
		node->next =NULL;
		}
		if (head==NULL){// first in list
		head=node;
		tail=node;
		}
    }
    T peek_back() {
		return tail->data;
    }
    void pop_back() {  
		Node<T> * node = tail->prev;
        delete tail;
        tail = node;
		if (node!=NULL){
		node->next=NULL;//
		}
		else{
			head=NULL;
		}
    }
    bool empty() {
		return head == NULL && tail == NULL;
	}
	Node<T> * begin (){
		return head;
	}
	Node<T> * end (){
		return NULL;
	}
	Node<T> * last (){
		return tail;
	}
	int size(){
		int result= 0;
		for (Node<T> * pointer = head; pointer !=NULL; pointer=pointer->next){
			result++;	
		}
		return result;
	}
private:
    Node<T> * head;
    Node<T> * tail;
};


