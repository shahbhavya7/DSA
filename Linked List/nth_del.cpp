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
    Node *deleteNth(int n);

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

Node *LinkedList::deleteNth(int n)
{
    Node *p, *q = NULL ;
    if (head == NULL || n <= 0)
        return NULL; // if list is empty
    p = head;

    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    p = head;
    if (n > length)
        return NULL;        // if n is greater than length of list
    int count = length - n; // count of nodes to traverse
    if (count == 0)
    {                      // if n is equal to length of list
        head = head->next; // delete the first node
        delete p;          // free memory
        return head;
    }
    for (int i = 0; i < count; i++)
    {
        q = p;       // keep track of previous node
        p = p->next; // move to next node
    }

    q->next = p->next; // link previous node to next node of node to be deleted
    delete p;          // free memory

    return head; // return head of modified list
}

int main()
{
    int A[] = {1};
    LinkedList list(A, 5);
    cout << "Original List: ";
    list.Display();
    int n = 1; // delete the 2nd last node
    list.deleteNth(n);
    cout << "List after deleting " << n << "th last node: ";
    list.Display();
    return 0;
}