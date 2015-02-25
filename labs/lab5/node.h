#ifndef TRIT_H
#define TRIT_H

template <typename T>
class Node {
public:
    Node(T d, Node * n, Node * p);
    Node(T d, Node * n) ;
    Node(T d);
    T data;
    Node * next;
    Node * prev;
};
#endif