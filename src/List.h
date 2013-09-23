#include <iostream>

#ifndef nullptr
#define nullptr NULL
#endif

template <class T>
class List
{
protected:
    struct Node {
        T data;
        Node *next;
        Node *prev;
        Node(T data, Node *prev = nullptr, Node *next = nullptr) : data(data), next(next), prev(prev) {}
    } *head, *last;
public:
    List();
    ~List();
    T popBack();
    T popFront();
    void pushBack(T data);
    void pushFront(T data);
    void empty();
    bool isEmpty();
    void print(std::ostream &out, const char *delimitr = " ");
};