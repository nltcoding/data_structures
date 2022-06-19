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

    void insert_node(int data)
    {
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = head;
            head = temp;
        }

    }

    void delete_node(int key)
    {
        Node *temp = head;
        Node *prev = NULL;

        // if the head is the key
        if (temp != NULL && temp->data == key)
        {
            head = temp->next;
            delete temp;
            return;
        }

        else
        {
            // iterate until key is found
            while((temp != NULL) && temp->data != key)
            {
                prev = temp;
                temp = temp->next;

            }
             // end of the list is met, key is not found
            if (temp == NULL)
            {
                return;
            }
            // remove the node with the specific key
            else
            {
                prev->next = temp->next;
                delete temp;
            }

        }

    }

    bool search_node(int key)
    {
        Node *current = head;

        while(current != NULL && current->data!= key)
        {
            current = current->next;
        }

        if (current != NULL && current->data == key)
        {
            return true;
        }
        else
        {
            return  false;
        }

    }

    int find_length()
    {
        if (head == NULL)
        {
            return 0;
        }
        Node *current = head;
        int count = 0;

        while(current != NULL)
        {
            count ++;
            current = current->next;
        }

        return count;
    }

    void print_linked_list()
    {
        Node *node = head;

        while (node != NULL)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
        std:: cout << std::endl;
    }
};

void simulate_linked_list()
{
    std:: cout << "Create a linked list with random integer at the head" << std::endl;

    Node *head = new Node();
    int head_data = rand()%10;
    head->data = head_data;

//    creates a linked list with head
    LinkedList *linked_list = new LinkedList();
    linked_list->head = head;

    linked_list->print_linked_list();

//  inserting 10 nodes to the linked list
    std:: cout << "Inserting 10 nodes to the linked list" << std::endl;
    std:: set<int> data_set;

    std::set<int>::iterator set_index;
    std::vector<int> data_vector;

    while (data_set.size() < 10) {
        data_set.insert(rand() % 100);
    }

//    insert 10 nodes with random numbers to the list
    for(set_index = data_set.begin(); set_index != data_set.end(); set_index++)
    {
        linked_list->insert_node(*set_index);
        data_vector.push_back(*set_index);
    }

    linked_list->print_linked_list();

//    find the length of the linked list
    std:: cout << "Length of the linked list: " << linked_list->find_length() << std::endl;

//    search for a node
    int search_node_data_1 = data_vector[rand()%10];

    std::cout << "Searching for node with value: " << search_node_data_1 << std::endl;
    bool node_available = linked_list->search_node(search_node_data_1);

    if (node_available)
    {
        std::cout << "Node Available" << std::endl;
    }
    else
    {
        std:: cout << "Node not found" << std:: endl;
    }

    int search_node_data_2 = 100 + rand() % 100;

    std:: cout << "Searching for node: " << search_node_data_2 << " Status: " << linked_list->search_node(search_node_data_2)
    << std::endl;

//    deleting a node
    int delete_node = data_vector[rand()%10];
    std:: cout << "Deleting Node: " << delete_node << std::endl;
    std:: cout << "Linked list before deletion" << std::endl;
    linked_list->print_linked_list();

    linked_list->delete_node(delete_node);
    std:: cout << "Linked list after deletion" << std::endl;
    linked_list->print_linked_list();

}


int main()
{
    simulate_linked_list();
    return 0;
}
