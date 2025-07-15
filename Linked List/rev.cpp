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
    Node *rev();

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

Node *LinkedList::rev()
{
    Node *prev = NULL, *curr = head, *future = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head; // No need to reverse if list is empty or has one element
    }
    while (curr != NULL)
    {
        future = curr->next; // store current's next node in future as current will be reversed
        curr->next = prev; // Reverse the current node's direction
        prev = curr;       // Move prev to the current node
        curr = future;       // Move to the next node
    }
    head = prev; // Update head to the new first node i.e. prev as curr and future will be NULL at the end of the loop
    return head;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList ll(A, 5);
    cout << "Original List: ";
    ll.Display();
    cout << "Reversed List: ";
    ll.rev();
    ll.Display();
    return 0;
}