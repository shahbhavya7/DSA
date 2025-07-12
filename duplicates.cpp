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
    Node *DelDuplicate();
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

Node *LinkedList::DelDuplicate()
{
    Node *p = head;
    Node *q = NULL;
    while (p && p->next)
    {
        if (p->data == p->next->data)
        {
            q = p->next;
            p->next = q->next;
            delete q;
        }
        else
        {
            p = p->next;
        }
    }
    return head;
}

int main()
{
    int A[] = {1, 2, 2, 3, 3};
    LinkedList ll(A, 5);
    ll.Display();
    // Deleting duplicates
    ll.DelDuplicate();
    ll.Display();

    return 0;
}