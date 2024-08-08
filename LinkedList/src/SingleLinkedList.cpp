#include <iostream>
#include <SingleLinkedList.hpp>

void ListNode::displayList(ListNode *node)
{
    std::cout << "\nThe nodes contains:"
              << std::endl;
    ListNode *current = node;
    while (current != NULL)
    {

        std::cout << current->val << std::endl;
        current = current->next;
    }
}

SingleLinkedList::SingleLinkedList() : head(nullptr) {}

SingleLinkedList::~SingleLinkedList()
{
    ListNode *current = head;
    ListNode *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SingleLinkedList::insertAtBack(int val)
{
    ListNode *newNode = new ListNode(val);
    nNodes++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    ListNode *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void SingleLinkedList::insertAtHead(int val)
{
    ListNode *newNode = new ListNode(val);
    nNodes++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int SingleLinkedList::getNumberNodes()
{
    return nNodes;
}

ListNode *SingleLinkedList::getHead()
{
    return head;
}

void SingleLinkedList::displayList()
{
    std::cout << "\nSingle Linked List with " << getNumberNodes() << " elements:"
              << std::endl;
    ListNode *current = head;
    while (current != NULL)
    {

        std::cout << current->val << std::endl;
        current = current->next;
    }
}
