#include <iostream>
#include <climits>
#include <Manager.hpp>

SingleLinkedList Manager::mergeTwoSortedLists(ListNode *l1, ListNode *l2)
{
    SingleLinkedList newLinkedList;

    while (l1 != NULL || l2 != NULL)
    {
        int value;
        int x = l1 ? l1->val : INT_MAX;
        int y = l2 ? l2->val : INT_MAX;

        if (l1 == NULL)
        {
            value = l2->val;
            l2 = l2 ? l2->next : nullptr;
        }
        else if (l2 == NULL)
        {
            value = l1->val;
            l1 = l1 ? l1->next : nullptr;
        }
        else if (x <= y)
        {
            value = l1->val;
            l1 = l1 ? l1->next : nullptr;
        }
        else
        {
            value = l2->val;
            l2 = l2 ? l2->next : nullptr;
        }
        newLinkedList.insertAtBack(value);
    }
    return newLinkedList;
}

SingleLinkedList Manager::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    SingleLinkedList sNew;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        sNew.insertAtBack(sum % 10);
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return sNew;
}

void splitList(ListNode *partitionA, ListNode *partitionB)
{
}
void Manager::sortList(ListNode *l1)
{
    if (l1 == NULL)
    {
        return;
    }

    // FIXME !!
    // ListNode *partitionA;
    // ListNode *partitionB;

    // splitList(partitionA, partitionB);

    // sortList(partitionA);
    // sortList(partitionB);
    // l1 = mergeTwoSortedLists(partitionA, partitionB);
}