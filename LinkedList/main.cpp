#include "linkedList.h"

int main()
{
    LinkedList list;

    list.insert_at_index(10, 0);   // List: 10
    list.print();
    list.insert_at_index(20, 1);   // List: 10 -> 20
    list.print();
    list.insert_at_index(5, 0);    // List: 5 -> 10 -> 20
    list.print();
    list.insert_at_index(30, 3);   // List: 5 -> 10 -> 20 -> 30
    list.print();
    list.insert_at_index(15, 2);   // List: 5 -> 10 -> 15 -> 20 -> 30
    list.print();

    list.reverse();
    list.print();
   
    return 0;
}