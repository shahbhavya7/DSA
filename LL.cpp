#include <bits/stdc++.h>
using namespace std;

class Node
{ // Node class to represent each node in the linked list
public:
    int data;
    Node *next;
};

class LinkedList
{ // LinkedList class to manage the linked list operations
private:
    Node *head; // initialize head pointer of type Node

public:
    LinkedList()
    { // Constructor making head as NULL
        head = NULL;
    }
    LinkedList(int A[], int n); //- Constructor to create a linked list from an array
    ~LinkedList();              // Destructor to delete the linked list

    void Display();                //- Display the linked list using display function
    void Insert(int index, int x); //- Insert a node at a given index
    int Delete(int index);         //- Delete a node at a given index
    int Length();                  //- Return the length of the linked list
};

//- Important Note: 
//  whenever you make a node like node *p , here p is not a node, it is a pointer to a node, so you have to allocate memory for it do it like
//  node* p ; you can never assign values to nodes directly, for that you need help of pointers, so to insert value in a new node you have to access 
//  it via pointer like p->data = value , p->next = NULL ; p is able to access the data and next members of the Node class as p pointer is of 
//  type Node, so it can access the members of Node class , so p->data is same as (*p).data, p->next is same as (*p).next that's why whenever 
//  I cout p, it gives the address of the node, because p is a pointer to a node, so it gives the address of the node, whenever you request 
//  memory for pointer you do node *p and when you request memory for a node you do p = new Node , this allocates memory at the location where p is 
//  pointing,


LinkedList::LinkedList(int A[], int n)
{ // defining the constructor to create a linked list from an array
    Node *last, *t;    // allocating memory for last and t pointers of type Node
    head = new Node;   // gives memory to the head node, memory is allocated dynamically of size of Node
    head->data = A[0]; // assigning the first element of the array to the data of head node
    head->next = NULL; // initializing the next pointer of head node to NULL
    last = head;       // last pointer is used to keep track of the last node in the linked list and for connecting new nodes

    for (int i = 1; i < n; i++)
    {                   // loop to create the rest of the array elements as nodes in the linked list
        t = new Node;   // creating a temporary node at address where t is pointing, memory is allocated dynamically of size of Node
        t->data = A[i]; // assigning the data of the temporary node to the next element of the array using pointer t
        t->next = NULL; // initializing the next pointer of the temporary node to NULL
        last->next = t; // connecting the last node to the temporary node
        last = t;       // updating the last pointer to point to the temporary node as new last node
    }
}

LinkedList::~LinkedList()
{ // defining the destructor to delete the linked list
    Node *p = head;
    while (head)
    {                      // deletes each node one by one by freeing the memory
        head = head->next; // moving the head pointer to the next node
        delete p;          // freeing the memory allocated to the current node
        p = head;          // updating the pointer p to point to the new head node
    }
}

void LinkedList::Display()
{ // defining the display function to display the linked list
    Node *p = head;  // initializing pointer p to head node, means that address which head is pointing , p also points there now
    while (p)
    {
        if (p->next != NULL)
        {                              
            cout << p->data<<" ("<<p<<") "<<" ("<<p->next<<") "<< " -> "; // print the data of the last node with an arrow if it is not the last node
            // just cout p gives the address of the node , cout p->next gives the address of the next node
            p = p->next;                // move to the next node
        }
        else
        {
            cout << p->data<<" ("<<p<<") "<<" ("<<p->next<<") "; // print the data of the last node without an arrow
            p = p->next;    // move to the next node
        }
    }
    cout << endl;
}

int LinkedList::Length()
{ // defining the length function to return the length of the linked list
    Node *p = head;
    int len = 0; // initialize length to 0
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    l.Display();
    cout << "Length of linked list: " << l.Length() << endl;
    return 0;
}