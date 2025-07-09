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
    bool ispalindrome();
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

bool LinkedList::ispalindrome() { 
    if (!head || !head->next) // Empty or single element list is a palindrome
        return true;
    // Find the middle
    Node *slow = head, *fast = head; // Use slow and fast pointers to find the middle
    while (fast->next && fast->next->next) {
        slow = slow->next; //
        fast = fast->next->next;
    }
    // Reverse second half
    Node *prev = nullptr, *curr = slow->next, *next = nullptr; // Start reversing from the node after slow i.e after the middle
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Compare halves
    Node *first = head, *second = prev; // 'prev' now points to the head of the reversed second half so we can compare it with the first half
    while (second) { // till the end of the second half
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

int main()
{
    int A[] = {1, 2, 2, 1}; // this is a palindrome
    LinkedList ll(A, 4);
    ll.Display();
    // Creating a cycle for testing
    if (ll.ispalindrome()) {
        ll.Display();
        cout << "The linked list is a palindrome." << endl;
    } else {
        ll.Display();
        cout << "The linked list is not a palindrome." << endl;
    }
 


    return 0;
}