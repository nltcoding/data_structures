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

tree_space::Node* BinaryTree::predecessor(tree_space::Node *node)
{
    tree_space::Node *temp = node;

    while(node != nullptr)
    {
        temp = node;
        node = node->right;
    }

    return temp;
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
//            free(root);
            return nullptr;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            tree_space::Node *temp = root->left;
            free(root);
            return temp;

        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            tree_space::Node *temp = root -> right;
            free(root);
            return temp;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            tree_space::Node *min_val = predecessor(root->left);
            root->data = min_val->data;
            root->left = delete_node(root->left, min_val->data);
        }
    }
    return root;
}

int BinaryTree::count_nodes(tree_space::Node *node, int count)
{

    if (node == nullptr)
    {
        return 0;
    }
    count += (1 + count_nodes(node->left, count) + count_nodes(node->right, count));

    return count;
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
    int TREE_NODES = 15;
//    create a root node
    tree_space::Node *root = new tree_space::Node();

//    create a binary tree
    BinaryTree *tree = new BinaryTree();

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

    root->data = data_vector[0];
    tree->root = root;

    std::random_device rd;
    std::shuffle(data_vector.begin(), data_vector.end(), rd);

    for (auto i = data_vector.begin() + 1; i != data_vector.end(); i++) {
        tree->insert(*i, root);
    }

    const std::string prefix = "";
//    print the binary tree
    std::cout << "Tree After Insertion" << std::endl;
    tree->print_tree("", tree->root, false);

//    counting nodes
    std::cout << "Number of Nodes: " << tree->count_nodes(tree->root, 0)
    << std:: endl;
//    delete a node
    int removing_index = 2;//rand() % TREE_NODES;
    int removing_node = data_vector[removing_index];

    std::cout << "Deleting node " << removing_node << std::endl;

    tree->delete_node(tree->root, removing_node);

    std:: cout << "Tree after deleting" << std::endl;
    tree->print_tree("", tree->root, false);

    std::cout << "Number of Nodes: " << tree->count_nodes(tree->root, 0)
              << std:: endl;


}



