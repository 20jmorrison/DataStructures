#include "linkedList.h"
#include <iostream>
using namespace std;


// ----------------------------------- PUBLIC FUNCTIONS -----------------------------------

LinkedList::LinkedList()
{
    num_nodes = 0;
    head = nullptr;
}

void LinkedList::insert_at_index(int value, int index)
{
    Node *new_node = new Node();
    new_node->data = value;

    // If the list is empty
    if (head == nullptr)
    {
        insert_into_empty(new_node);
    }

    // If inserting at beginning of list
    else if (index == 0)
    {
        insert_at_beginning(new_node);
    }

    // If inserting at end of list
    else if (index == num_nodes)
    {
        insert_at_end(new_node);
    }

    // Otherwise, we can just insert at specified position
    else
    {
        Node* temp = head;
        int i = 0;

        while (i != index)                  // Getting to desired index
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp;              // Pointing new nodes next to the node currently in the desired index
        new_node->prev = temp->prev;        // Point new nodes prev to the prev of the node currently in the desired position
        new_node->prev->next = new_node;    // Pointing prev nodes next to new node
        temp->prev = new_node;              // Point next nodes prev to new node
        num_nodes++;                        // Incrementing num_nodes
    }
}

void LinkedList::remove_at_index(int index)
{
    // If the list is already empty
    if (head == nullptr)
    {
        return;
    }

    // If there is only one node
    if (num_nodes == 1)
    {
        remove_only_node();
    }

    // If the index to remove is the very beginning
    else if (index == 0)
    {
        remove_at_beginning();
    }

    // If the index to remove is the very end
    else if (index == num_nodes - 1)
    {
        remove_at_end();
    }

    // Otherwise, just remove at given index
    else{
        Node* temp = head;
        int i = 0;
        while (i != index)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        num_nodes--;
    }
}

int LinkedList::size()
{
    return num_nodes;
}

void LinkedList::reverse()
{
    // Do nothing if the list is empty or has only one element
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node* prev_node = nullptr;
    Node* curr_node = head;

    while (curr_node != nullptr)
    {
        // Update prev_node
        prev_node = curr_node->prev;

        // Swap curr_nodes next and prev
        curr_node->prev = curr_node->next;
        curr_node->next = prev_node;

        head = curr_node;
        curr_node = curr_node->prev;
    }
}

void LinkedList::print()
{
    Node* temp = head;
    cout << endl;
    while(temp != nullptr)
    {
        cout << "[" << temp->data << "] <-> ";
        temp = temp->next;
    }
    cout << "nullptr\n";

}



// ----------------------------------- PRIVATE FUNCTIONS ----------------------------------

void LinkedList::insert_into_empty(Node*& node_to_insert)
{
    head = node_to_insert;              // Point head to new node
    node_to_insert->prev = nullptr;     // Point new node prev to nullptr
    node_to_insert->next = nullptr;     // Point new node next to nullptr
    num_nodes++;                        // Increment num_nodes
}

void LinkedList::insert_at_beginning(Node*& node_to_insert)
{
    node_to_insert->next = head;        // Point new node next to the current head
    node_to_insert->prev = nullptr;     // Point new node prev to nullptr
    head->prev = node_to_insert;        // Point current head prev to new node
    head = node_to_insert;              // Update head to point at new node
    num_nodes++;                        // Increment num_nodes
}

void LinkedList::insert_at_end(Node*& node_to_insert)
{
    Node* temp = head;
    
    while (temp->next != nullptr)       // Getting to end of list
    {
        temp = temp->next;
    }

    node_to_insert->prev = temp;        // Point new node to end node
    node_to_insert->next = nullptr;     // Point next of new node to nullptr
    temp->next = node_to_insert;        // Point old end node to new node
    num_nodes++;                        // Increment num_nodes
}

void LinkedList::remove_only_node()
{
    delete head;        // Delete node pointed to by head
    head = nullptr;     // Set head to nullptr
    num_nodes--;        // Decrement num_nodes
}

void LinkedList::remove_at_beginning()
{
    Node* temp = head;          // Store current head for deletion
    head = head->next;          // Move head to the next node
    head->prev = nullptr;       // Set the new heads prev to nullptr
    delete temp;                // Delete old head
    num_nodes--;                // Decrement num_nodes
}

void LinkedList::remove_at_end()
{
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    num_nodes--;
}