#include <iostream>
#include <string>

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
	Node * next;
    Node * prev;
};
