#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *gethead(); // Private function to get the head

public:
    LinkedList();
    void insertAscending(int value);
    LinkedList mergeLists(LinkedList &list2);
    void display();
};

#endif // LINKEDLIST_H