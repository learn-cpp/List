#include <iostream>
#include "src/List.cpp"

int main(int argc, const char * argv[])
{
    List<int> l;
    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(6);
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);

    l.print(std::cout);
    return 0;
}