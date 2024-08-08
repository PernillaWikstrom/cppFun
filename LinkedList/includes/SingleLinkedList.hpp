#include <iostream>

#pragma once

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

public:
    void displayList(ListNode *node);
    ~ListNode() {}
};

class SingleLinkedList
{

private:
    ListNode *head;

public:
    int nNodes = 0;
    SingleLinkedList();
    ~SingleLinkedList();
    void insertAtBack(int val);

    void insertAtHead(int val);

    int getNumberNodes();

    ListNode *getHead();

    void displayList();
};
