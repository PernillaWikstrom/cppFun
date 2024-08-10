#include <iostream>
#include <Manager.hpp>

Node *mergeTwoSortedLists(Node *n1, Node *n2)
{
    // Base cases when either nodes are null
    if (n1 == NULL)
    {
        return n2;
    }
    else if (n2 == NULL)
    {
        return n1;
    }

    Node *tmp = NULL;

    // Takes the next node from n1 if its
    // data is smaller or equal to n2s data
    if (n1->data <= n2->data)
    {
        tmp = n1;
        tmp->next = mergeTwoSortedLists(n1->next, n2);
        return tmp;
    }

    // Otherwise takes the next node from n2
    tmp = n2;
    tmp->next = mergeTwoSortedLists(n1, n2->next);
    return tmp;
}

SingleLinkedList addTwoNumbers(Node *n1, Node *n2)
{
    SingleLinkedList sNew;
    int carry = 0;
    // Iterate until empty
    while (n1 != NULL || n2 != NULL || carry != 0)
    {
        int x = n1 ? n1->data : 0;
        int y = n2 ? n2->data : 0;
        // Sum of the data
        int sum = carry + x + y;
        // Integer division where everything above
        // 10 will be be carried over to the next
        carry = sum / 10;
        // The remainder will be inserted at back
        sNew.insertAtBack(sum % 10);
        n1 = n1 ? n1->next : nullptr;
        n2 = n2 ? n2->next : nullptr;
    }
    return sNew;
}

void splitList(Node *origin, Node **partitionA, Node **partitionB)
{
    // Creates two pointers in scope
    Node *left;
    Node *right;
    // Copy the head and the next node
    left = origin;
    right = origin->next;

    // Find midpoint by advance the right pointer twice per
    // left pointer to node until reaching the right nullpointer
    while (right != NULL)
    {
        right = right->next;
        if (right != NULL)
        {
            left = left->next;
            right = right->next;
        }
    }

    // Partition A start pointing at the origins head
    *partitionA = origin;
    // Partition B start pointing at the midpoint
    *partitionB = left->next;

    // Detach all nodes from the midpoint.
    // (Since left points to origin it is affected and
    // origin will points to a list that ends at the midpoint)
    left->next = NULL;
}

void mergeSortList(Node **n1)
{
    Node *head = *n1;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    // // // FIXME !!
    Node *partitionA;
    Node *partitionB;

    splitList(head, &partitionA, &partitionB);

    mergeSortList(&partitionA);
    mergeSortList(&partitionB);

    *n1 = mergeTwoSortedLists(partitionA, partitionB);
}