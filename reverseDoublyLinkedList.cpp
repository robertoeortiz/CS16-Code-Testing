#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node* createNode(int d)
{
    Node *node = new Node;
    node->data = d;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void reverseDoublyLinkedList(Node*& head)
{
    if(!head)
    {
        return;
    }

    Node *curr = head;
    while(curr->next)
    {
        curr = curr->next;
    }

    head = curr; //head is now the tail

    while(curr)
    {
        Node *before = curr->prev;
        curr->prev = curr->next;
        curr->next = before;
        curr = before;
    }
}

void printList(Node*head)
{
    Node *curr = head;
    while(curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *n1 = createNode(3);
    Node *n2 = createNode(4);
    Node *n3 = createNode(5);
    Node *n4 = createNode(6);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    printList(n1);
    cout << endl;

    reverseDoublyLinkedList(n1);
    printList(n1);
    cout << endl;
}