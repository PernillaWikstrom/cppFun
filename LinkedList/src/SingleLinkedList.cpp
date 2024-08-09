#include <iostream>
#include <SingleLinkedList.hpp>

void ListNode::displayList()
{
    ListNode *current = this;
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
