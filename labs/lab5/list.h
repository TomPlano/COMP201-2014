#ifndef TRIT_H
#define TRIT_H

template <typename T>  
	List::List();
    void List::push_front(T element);
    T List::peek_front();
    void List::pop_front();
    void List::push_back(T element);
    T List::peek_back();
    void List::pop_back();
    bool List::empty();
	Node<T> * List:: begin ();
	Node<T> * List::end ();
	Node<T> * List::last ();
	int List::size();
	#endif