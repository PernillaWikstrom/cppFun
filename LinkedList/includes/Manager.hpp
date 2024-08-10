#include <iostream>
#include <SingleLinkedList.hpp>

#pragma once

/**
 * @brief Sums the nodes data from two linked
 * lists and creates a new linked list
 *
 * @param n1: Pointer to a Node
 * @param n2: Pointer to a Node
 *
 * @returns SingleLinkedList
 *
 */
SingleLinkedList addTwoNumbers(Node *n1, Node *n2);

/**
 * @brief Merges two sorted lists recursively
 *
 * @param n1: Pointer to a Node
 * @param n2: Pointer to a Node
 *
 * @returns Pointer to a Node
 *
 */
Node *mergeTwoSortedLists(Node *n1, Node *n2);

/**
 * @brief Splits the linked list in two partitions by
 * finding the midpoint. The double pointers (partitionA/B)
 * gets modified as they are passed by referencee as arguments.
 *
 * @param origin: Single pointer to a Node
 * @param partitionA: Double pointer to a Node
 * @param partitionA: Double pointer to a Node
 *
 */
void splitList(Node *origin, Node **partitionA, Node **partitionB);

/**
 * @brief Sorts a list using MergeSort recursively.
 * Splits the original node object in two partitions
 * until the partitions are single units.
 * Then merges the single units by value of data.
 *
 * @param n1: Pointer to a Node
 */
void mergeSortList(Node **n1);
