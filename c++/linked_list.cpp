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

    }

    void print_linked_list(Node* node)
    {
        while (node != NULL)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
    }
};

int main()
{
    LinkedList *llist = new LinkedList();

    Node *head = new Node();
    head->data = 7;

    llist->head = head;

    llist->insert_node(8);
    llist->print_linked_list(llist->head);

    std::cout << "Thilina";

    return 0;
}
