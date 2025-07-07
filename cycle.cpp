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
    bool iscycle();
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

bool LinkedList::iscycle(){ // using Floyd's Cycle Detection Algorithm (Tortoise and Hare)
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next){
        slow  = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList ll(A, 5);
    ll.Display();
    // Creating a cycle for testing
    Node *head = ll.getHead();
    Node *temp = ll.getHead();
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ll.getHead()->next; // Creating a cycle by linking last node to the second node
    if (ll.iscycle()) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }
    


    return 0;
}