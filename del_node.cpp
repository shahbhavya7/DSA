#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int A[], int n);
    void del(Node *p);

    void Display();
    Node* getHead() { return head; }
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while (p)
    {
        if (p->next != NULL)
        {
            cout << p->data << " -> ";
            p = p->next;
        }
        else
        {
            cout << p->data;
            p = p->next;
        }
    }
    cout << endl;
}

void LinkedList::del(Node *p){ // p is node to be deleted 
    p->data = p->next->data; // copy the data from the next node to the current node
    Node *temp = p->next; // store the next node in a temporary variable
    p->next = p->next->next; // link the current node to the node
    delete temp; // delete the node where temp is pointing to 

}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    l.Display(); // Display the original list
    Node *p = l.getHead()->next->next; // Let's say we want to delete the node with value 3
    l.del(p); // Delete the node with value 3
    l.Display(); // Display the list after deletion
    // Expected output: 1 -> 2 -> 4 -> 5

    return 0;
}