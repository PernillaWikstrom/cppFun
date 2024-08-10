#include <iostream>
#include <SingleLinkedList.hpp>

void Node::displayList()
{
    Node *current = this;
    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

SingleLinkedList::SingleLinkedList() : head(nullptr), nNodes(0) {}

SingleLinkedList::~SingleLinkedList()
{
    Node *current = head;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SingleLinkedList::insertAtBack(int data)
{
    Node *newNode = new Node(data);

    // Increment number nodes
    nNodes++;

    // Sets head to newNode if
    // head is uninitialized
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Iterate through the linked list
    // until reaching the last node
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    // Assign newNode at back
    current->next = newNode;
}

void SingleLinkedList::insertAtHead(int data)
{
    Node *newNode = new Node(data);

    // Increment number nodes
    nNodes++;

    // Sets head to newNode if
    // head is uninitialized
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    // Assign head as next
    newNode->next = head;
    // Update head to the new node
    head = newNode;
}

int SingleLinkedList::getNumberNodes()
{
    return nNodes;
}

Node *SingleLinkedList::getHead()
{
    return head;
}

void SingleLinkedList::displayList()
{
    if (head != nullptr)
    {
        std::cout << "\nSingle Linked List with " << getNumberNodes() << " elements:"
                  << std::endl;
        head->displayList();
        return;
    }
    std::cout << "\nSingle Linked List is empty"
              << std::endl;
}
