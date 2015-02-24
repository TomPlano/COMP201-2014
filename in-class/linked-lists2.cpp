#include <iostream>
#include <string>
// #define NULL ((void *)0)
template <typename T>
class Node {
public:
    Node(T d, Node * n, Node * p) { 
	data = d; next = n; prev = p;
	}
	
    Node(T d, Node * n) { 
	data = d; next = n; prev = NULL; 
	}
	
    Node(T d){ 
	data = d; next = NULL; prev = NULL;
	}
	
    T data;
    Node * next;
    Node * prev;
};

template <typename T>
class Stack {
public:
    Stack() {
        head = NULL;
    }
    void push (T data) {
        Node<T> * node = new Node<T>(data, head);
        head = node;
    }
    void pop() {
        Node<T> * node = head->next;
        delete head;
        head = node;
    }
    T top() {
        return head->data;
    }
    bool empty() {
        return head == NULL;
    }
private:
    Node<T> * head;
};


template <typename T>
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

int main() {
    List<int> numbers;
    numbers.push_back(42);
    // 42
    numbers.push_front(10);
    // 10, 42
    numbers.push_front(3);
    // 3, 10, 42
    numbers.push_back(87);
    // 3, 10, 42, 87
    std::cout << (3 == numbers.peek_front()) << std::endl;
	
    std::cout << (87 == numbers.peek_back()) << std::endl;
    numbers.pop_front();
    // 10, 42, 87
    std::cout << (10 == numbers.peek_front()) << std::endl;
    numbers.pop_back();
    // 10, 42
    std::cout << (42 == numbers.peek_back()) << std::endl;
    std::cout << (!numbers.empty()) << std::endl;
    numbers.pop_front();
    // 10
    numbers.pop_front();
    // Empty
    std::cout << numbers.empty() << std::endl;

    
    return 0;
}


