//
// Created by thilina on 19/06/22.
//

#ifndef C___BINARY_TREE_H
#define C___BINARY_TREE_H

#include <iostream>
#include <vector>
#include <set>

namespace tree_space {

    class Node {
    public:
        int data;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int data);

        Node();

    };
}

class BinaryTree
{
public:
    tree_space::Node *root = nullptr;

    void insert(int value, tree_space::Node *node);
    tree_space::Node* predecessor(tree_space::Node *node);
    int count_nodes(tree_space::Node *node, int count);
    tree_space::Node *delete_node(tree_space::Node *root, int value);
    void print_tree(const std::string &prefix, const tree_space::Node *node, bool is_left);

};

void simulate_binary_tree();

#endif //C___BINARY_TREE_H
