#include <iostream>
#include <climits>
#include <Manager.hpp>

ListNode *Manager::mergeTwoSortedLists(ListNode *l1, ListNode *l2)
{
    ListNode *result = NULL;

    if (l1 == NULL)
        return (l2);
    else if (l2 == NULL)
        return (l1);

    if (l1->val <= l2->val)
    {
        result = l1;
        result->next = mergeTwoSortedLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeTwoSortedLists(l1, l2->next);
    }
    return result;
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

// Copy list into two subarrays
void splitList(ListNode *origin, ListNode **partitionA, ListNode **partitionB)
{
    ListNode *left;
    ListNode *right;
    left = origin;
    right = origin->next;

    /* Advance 'left' two nodes, and advance 'right' one node
     */
    while (right != NULL)
    {
        right = right->next;
        if (right != NULL)
        {
            left = left->next;
            right = right->next;
        }
    }

    /* 'left' is ... */
    *partitionA = origin;
    *partitionB = left->next;
    left->next = NULL;
}

void Manager::mergeSortList(ListNode **l1)
{
    ListNode *head = *l1;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    // // // FIXME !!
    ListNode *partitionA;
    ListNode *partitionB;

    // // // split until
    splitList(head, &partitionA, &partitionB);

    mergeSortList(&partitionA);
    mergeSortList(&partitionB);

    *l1 = mergeTwoSortedLists(partitionA, partitionB);
}