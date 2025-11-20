#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int removeMax(Node *&head)
{
    if(!head)
    {
        cout << "Error, null linked list" << endl;
        return 0;
    }

    Node *maxNode = head;
    Node *curr = head->next;
    Node *after = nullptr;
    Node *prev = head;
    Node *prevMaxNode = head;

    while (curr) 
    {
        if(curr->data > maxNode->data)
        {
            maxNode = curr;
            after = maxNode->next;
            prevMaxNode = prev;
        }
        prev = prev->next;
        curr = curr->next;
    }

    if(maxNode == head)
    {
        head = head->next;
    }

    int max = maxNode->data;
    delete maxNode;
    prevMaxNode->next = after;
    return max;
}

void printList(Node*head)
{
    Node *curr = head;
    while(curr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node;
    head->data = 3;
    Node *second = new Node;
    second->data = 2;

    head->next = second;

    Node *third = new Node;
    third->data = -1;
    second->next = third;
    third->next = nullptr;

    printList(head);

    cout << endl;

    int max = removeMax(head);
    cout << "Max value: " << max << endl;
    printList(head);
}