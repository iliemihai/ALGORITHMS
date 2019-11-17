#include "../lib/DoubleLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    DoublyLinkedList<int> dll;
	dll.addLast(4);
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);

    dll.addFirst(-1);
    dll.addFirst(-2);
    dll.addFirst(-3);
    dll.addFirst(-4);

    std::cout << "Linked list after adding some elements: " << dll << std::endl;

}