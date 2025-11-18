#include <iostream>
using namespace std;

//this was me messing around with stuff!

struct Node
{
    int data;
    Node *next;
};

Node* findTail(Node *head) 
{
    if(head == nullptr)
    {
        return nullptr;
    }
    Node *curr = head;
    while(curr->next)
    {
        curr = curr->next;
    }
    return curr;
}

void deleteLinkedList(Node*& head)
{
    //IF WE DO NOT PASS BY REFERENCE/MAKE AN ALIAS, then head will NOT get deleted. Only the local head will be, but NOT THE OG POINTER!!!
    Node *curr = head;

    while (curr)
    {
        Node *temp = curr->next;
        delete (curr);
        curr = temp;
    }

    head = nullptr;
}

void prepend(Node*& head, int newValue)
{
    Node *newNode = new Node;
    newNode->data = newValue;
    newNode->next = head;

    head = newNode; //we MUST alter the value of head at the end, so we need & in the function header so that is is saved to head in MAIN
}

void append(Node* head, int newValue)
{
    Node *tail = findTail(head);
    Node *newNode = new Node;
    newNode->data = newValue;
    newNode->next = nullptr;
    tail->next = newNode;
  
}

void removeTail(Node*& head)
{
    Node *newTail;
    Node *curr = head; // contains the current tail

    if(head == nullptr)
    {
        return;
    }

    if(!curr->next) //if head->next is NOT defined, then curr/the head is also the tail (linked list of only length 1). Make head a nullptr
    {
        delete (curr);
        head = nullptr; 
        return;
    }

    while(curr->next->next)
    {
        curr = curr->next;
    }
    //curr now contains the 2nd to last element 
    newTail = curr;
    newTail->next = nullptr;
    curr = curr->next; // now curr is the final element that will get deleted
    delete (curr);
}


//Precondition: index is valid
void addAfterPosition(Node*& head, int index, int newValue) //index starts at 0. Place right afterAFTER index
{
    Node *newNode = new Node;
    Node *curr = head;
    newNode->data = newValue;
    int counter = 0;

    while (curr && counter != index)
    {
        curr = curr->next;
        counter++;
    }
    if(!curr->next)
    {
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = curr->next;
    }

    curr->next = newNode;
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

void reverse(Node*& head)
{
    Node *previous = nullptr; // holds the node before curr
    Node *curr = head;
    while (curr) // curr will be NULL after the loop
    {
        Node *newNode = curr->next; //to store the element AFTER curr so it doesn't get deleted
        curr->next = previous; //1st element (old head/new tail) will correctly set to null!
        previous = curr; 
        curr = newNode;
    }

    head = previous;
}

int main()
{
    Node *head = new Node; //if you try to just initialize rn, it won't work. NEED to put it in the heap first.
    head->data = 1;
    head->next = nullptr;
    append(head, 2);
    append(head, 3);
    prepend(head, -1);
    addAfterPosition(head, 3, 6);

    printList(head);

    cout << endl;
    removeTail(head);
    printList(head);
    cout << endl;

    cout << endl;
    reverse(head);
    printList(head);

    deleteLinkedList(head);

    if(head == nullptr)
    {
        cout << "I deleted the list successfully!" << endl;
    }

    return 1;
}