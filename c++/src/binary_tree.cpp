//
// Created by thilina on 19/06/22.
//
#include <iostream>
#include "../lib/binary_tree.h"
#include <algorithm>
#include <random>


 tree_space::Node::Node(int data)
{
    this->data = data;
}

tree_space::Node::Node()
= default;

void BinaryTree::insert(int value, tree_space::Node *node)
{

    if (value < node->data)
    {
        if(node->left != nullptr)
        {
            insert(value, node->left);
        }
        else
        {
            node->left = new tree_space::Node();
            node->left->data = value;
        }
    }
    else
    {
        if (node->right != nullptr)
        {
            insert(value, node->right);
        }
        else
        {
            node->right = new tree_space::Node();
            node->right->data = value;
        }
    }
}

tree_space::Node* BinaryTree::delete_node(tree_space::Node *root, int value)
{

// if the root is null
    if (root == nullptr)
    {
        return root;
    }
// the node is in the right sub tree
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
//    the node is in the left sub tree
    else if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
//    the node has the value
    else
    {
        if (root->left == nullptr && root->left == nullptr)
        {

        }
    }

//    if the node with value has only one child
//    if the node with value has two children
}

void BinaryTree::print_tree(const std::string &prefix, const tree_space::Node *node, bool is_left)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (is_left ? "├──" : "└──" );
        // print the value of the node
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        print_tree(prefix + (is_left ? "|   " : "    "), node->right, true);
        print_tree(prefix + (is_left ? "|   " : "    "), node->left, false);
    }
}

void simulate_binary_tree() {
    int TREE_NODES = 25;
//    create a root node
    tree_space::Node *root = new tree_space::Node(10);

//    create a binary tree
    BinaryTree *tree = new BinaryTree();
    tree->root = root;

//    create a set of nodes
    std::set<int> data_set;

    std::set<int>::iterator set_index;
    std::vector<int> data_vector;

    while (data_set.size() < TREE_NODES) {
        data_set.insert(rand() % 100);
    }

    for (set_index = data_set.begin(); set_index != data_set.end(); set_index++)
    {
        data_vector.push_back(*set_index);
    }


    std::random_device rd;
    std::shuffle(data_vector.begin(), data_vector.end(), rd);

    for (auto i = data_vector.begin(); i != data_vector.end(); i++) {
        tree->insert(*i, root);
    }

    const std::string prefix = "";
//    print the binary tree
    tree->print_tree("", root, false);

}



