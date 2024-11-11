#include <iostream>
#include "heap.h"

using namespace std;

void Heap::insert(int value)
{
    // Add new value to the end of the array
    values.push_back(value);

    // Get index of value we just added
    int index = values.size() - 1;

    // While our new value is greater than its parent, and it is not the root:
    while (values[index] > values[(index - 1) / 2] && index != 0)
    {
        swap(values[index], values[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void Heap::remove(int index_to_remove)
{
    values[index_to_remove] = values.back();
    values.pop_back();
    heapify(index_to_remove);
}

void Heap::heapify(int index)
{
    // Set the index of the largest value to the given index
    int index_of_largest = index;

    // Get index of largest's left and right children
    int index_of_left = 2 * index + 1;
    int index_of_right = 2 * index + 2;

    // If the index of left child exists and it's value is greater than the largest, update largest index
    if (index_of_left < values.size() && values[index_of_left] > values[index_of_largest])
    {
        index_of_largest = index_of_left;
    } 

    // If the index of right child exists and it's value is greater than the largest, update largest index
    if (index_of_right < values.size() && values[index_of_right] > values[index_of_largest])
    {
        index_of_largest = index_of_right;
    }

    // If index of largest has been updated, swap old largest and new largest values, and call heapify on the new largest
    if (index_of_largest != index)
    {
        swap(values[index], values[index_of_largest]);
        heapify(index_of_largest);
    }
}

void Heap::print()
{
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}