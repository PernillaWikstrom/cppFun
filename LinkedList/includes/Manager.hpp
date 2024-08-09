#include <iostream>
#include <SingleLinkedList.hpp>

#pragma once

class Manager
{

public:
    SingleLinkedList addTwoNumbers(ListNode *l1, ListNode *l2);
    // SingleLinkedList mergeTwoSortedLists(ListNode *l1, ListNode *l2);
    void mergeSortList(ListNode **l1);
    void displayNode(ListNode *node);
    ListNode *mergeTwoSortedLists(ListNode *l1, ListNode *l2);
};
