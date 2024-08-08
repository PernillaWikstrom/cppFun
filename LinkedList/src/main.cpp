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

    Manager s;
    SingleLinkedList result = s.addTwoNumbers(s1.getHead(), s2.getHead());
    result.displayList();

    SingleLinkedList l1, l2;
    l1.insertAtBack(0);
    l1.insertAtBack(1);
    l1.insertAtBack(4);
    l1.insertAtBack(5);
    l1.insertAtBack(7);
    l1.displayList();
    l2.insertAtBack(-1);
    l2.insertAtBack(-2);
    l2.displayList();

    SingleLinkedList mergedLists = s.mergeTwoSortedLists(l1.getHead(), l2.getHead());
    mergedLists.displayList();
}