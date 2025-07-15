#include<bits/stdc++.h>
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
    Node *head1;
    Node *head2;

    LinkedList()
    {
        head = NULL;
        head1 = NULL;
        head2 = NULL;
    }
    LinkedList(int A[], int n);
    Node *merge();

    void Display(Node* p);
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

void LinkedList::Display(Node* p)
{
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

Node* LinkedList::merge(){
    Node *p1 = head1;
    Node *p2 = head2;
    Node *mergedHead = NULL;
    Node *temp = NULL;
    if(p1 == NULL) return p2;
    if(p2 == NULL) return p1;
    if(p1->data < p2->data){
        mergedHead = p1;
        p1 = p1->next;
    } else {
        mergedHead = p2;
        p2 = p2->next;
    }
    temp = mergedHead;
    // Merge the two lists
    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            temp->next = p1;
            temp = p1;
            p1 = p1->next;
        } else {
            temp->next = p2;
            temp = p2;
            p2 = p2->next;
        }
    }
    // If there are remaining nodes in either list, append them
    if(p1 != NULL){
        temp->next = p1;
    } else {
        temp->next = p2;
    }
    return mergedHead;
}

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    LinkedList list1(A, 5);
    LinkedList list2(B, 5);

    cout << "List 1: ";
    list1.Display(list1.getHead());
    cout << "List 2: ";
    list2.Display(list2.getHead());

    // Set head1 and head2 for merging
    list1.head1 = list1.getHead(); 
    list1.head2 = list2.getHead();

    Node* merged = list1.merge(); // Merge the two lists by calling the merge function via list1 object
    cout << "Merged List: ";
    list1.Display(merged);

 
    
    return 0;
}