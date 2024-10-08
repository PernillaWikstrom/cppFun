#include <iostream>
#include <Manager.hpp>

int main()
{
    SingleLinkedList s1;
    s1.insertAtHead(3);
    s1.insertAtHead(2);
    s1.insertAtHead(4);
    s1.insertAtHead(3);
    s1.displayList();

    SingleLinkedList s2;
    s2.insertAtHead(5);
    s2.insertAtHead(6);
    s2.insertAtHead(4);
    s2.displayList();

    SingleLinkedList result = addTwoNumbers(s1.getHead(), s2.getHead());
    result.displayList();

    SingleLinkedList g1;
    g1.insertAtBack(13);
    g1.insertAtBack(10);
    g1.insertAtBack(1);
    g1.insertAtBack(7);
    g1.displayList();

    Node *p1 = g1.getHead();
    mergeSortList(&p1);
    std::cout << "\nSingle Linked List sorted:"
              << std::endl;
    p1->displayList();

    SingleLinkedList g2;
    g2.insertAtBack(-13);
    g2.insertAtBack(130);
    g2.insertAtBack(12);
    g2.insertAtBack(72);
    g2.displayList();

    Node *p2 = g2.getHead();
    mergeSortList(&p2);
    std::cout << "\nSingle Linked List sorted:"
              << std::endl;
    p2->displayList();

    Node *mergedLists = mergeTwoSortedLists(p1, p2);
    std::cout << "\nSingle Linked Lists merged:"
              << std::endl;
    mergedLists->displayList();
}