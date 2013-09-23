#include "List.h"

template <class T>
List<T>::List()
{
    head = last = nullptr;
}

template <class T>
List<T>::~List()
{
    empty();
}

template <class T>
T List<T>::popBack()
{
    T result = last->data;
    last = last->prev;
    delete last->next;
    last->next = nullptr;
    return result;
}

template <class T>
T List<T>::popFront()
{
    T result = head->data;
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    return result;
}

template <class T>
void List<T>::pushBack(T data)
{
    if (!head) {
        head = new Node(data);
    } else if (!last) {
        head->next = last = new Node(data, head);
    } else {
        last = new Node(data, last);
        last->prev->next = last;
    }
}

template <class T>
void List<T>::pushFront(T data)
{
    if (!head) {
        head = new Node(data);
    } else if (!last) {
        last = head;
        last->prev = head = new Node(data, nullptr, last);
    } else {
        head = new Node(data, nullptr, head);
    }
}

template <class T>
bool List<T>::isEmpty()
{
    return head == last == nullptr;
}

template <class T>
void List<T>::empty()
{
    for (Node *it = head->next; it; it = it->next) {
        delete it->prev;
        it->prev = nullptr;
    }
}

template <class T>
void List<T>::print(std::ostream &out, const char *delimitr)
{
    for (Node *it = head; it; it = it->next) {
        out << it->data << delimitr;
    }
}