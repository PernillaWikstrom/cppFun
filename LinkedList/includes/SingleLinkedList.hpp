#include <iostream>

#pragma once

struct Node
{
    int data;
    Node *next;
    // Default constructor
    Node() : data(0), next(nullptr)
    {
    }
    // Parameterized constructor (single argument)
    Node(int x) : data(x), next(nullptr) {}
    // Parameterized constructor (two arguments)
    Node(int x, Node *next) : data(x), next(next) {}

public:
    // Display all nodes iteratively
    void displayList();
    // Default destructor
    ~Node() { next = nullptr; }
};

class SingleLinkedList
{

private:
    // Pointer to the current head as a Node obj
    Node *head;
    // Counter of number nodes in the linked list
    int nNodes;

public:
    // Default constructor
    SingleLinkedList();
    // Default destructor
    ~SingleLinkedList();

    // Insert new data at back of the linked list
    void insertAtBack(int data);
    // Insert new data at head of the linked list
    void insertAtHead(int data);

    // Returns an int of number nodes
    int getNumberNodes();

    // Returns a pointer to the current head
    Node *getHead();

    // Display the full
    void displayList();
};
