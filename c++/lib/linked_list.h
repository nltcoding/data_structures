//
// Created by thilina on 19/06/22.
//

#ifndef C___LINKED_LIST_H
#define C___LINKED_LIST_H

#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head = NULL;

    void insert_node(int data);
    void delete_node(int key);
    bool search_node(int key);
    int find_length();
    void print_linked_list();
};

void simulate_linked_list();

#endif //C___LINKED_LIST_H
