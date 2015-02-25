#include <iostream>
#include <string>
#include"node.h"

	Node::Node(T d, Node * n, Node * p) { 
	data = d; next = n; prev = p;
	}
	
	Node::Node(T d, Node * n) { 
	data = d; next = n; prev = NULL; 
	}
	
    Node::Node(T d){ 
	data = d; next = NULL; prev = NULL;
	}
