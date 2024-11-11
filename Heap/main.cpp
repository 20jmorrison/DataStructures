#include "heap.h"
#include <iostream>
using namespace std;

int main()
{
    Heap heap;

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    heap.print();

    heap.remove(2);

    heap.print();

    return 0;
}


// 45
// 5 15
// 2 4 3