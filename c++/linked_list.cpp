#include <cstdlib>
#include <iostream>

struct _Node
{
    int data;
    struct Node *link;
};

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

        if (current->data == key)
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

    std:: cout << "Inserting 10 nodes to the linked list" << std::endl;
//    insert 10 nodes with random numbers to the list
    for(int index = 0; index < 10; index++)
    {
        linked_list->insert_node(rand()%10);
    }

    linked_list->print_linked_list();

//    find the length of the linked list
    std:: cout << "Length of the linked list: " << linked_list->find_length() << std::endl;

//    search for a node

}


int main()
{
    simulate_linked_list();
    return 0;
}
