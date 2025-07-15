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
    Node *RemoveEl(int x);
    Node *getHead() { return head; } // Added to access head for cycle creation in main
    void Display();
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

Node *LinkedList::RemoveEl(int x)
{
    Node *p = head, *q = NULL;
    while (p)
    {
        if (p->data == x)
        {
            if (q == NULL)
            {
                head = p->next; // Remove head
                delete p;
                p = head; // Move to new head
            }
            else
            {
                q->next = p->next; // Remove non-head node
                delete p;
                p = q->next; // Move to next node
            }
        }
        // Move to next node
        else
        {
            q = p;       // Update previous node
            p = p->next; // Move to next node
        }
    }
    return head; // Return the modified head of the list
}

int main()
{
    int A[] = {1, 2, 2, 3, 3};
    LinkedList ll(A, 5);
    ll.Display();
    ll.RemoveEl(2); // Remove all occurrences of 2
    ll.Display();

    return 0;
}