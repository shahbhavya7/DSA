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
    LinkedList()
    { 
        head = NULL;
    }
    LinkedList(int A[], int n); 
    ~LinkedList();         

    void Display();
    Node* mid();
   
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
            cout << p->data<< " -> "; 
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

LinkedList::~LinkedList()
{ 
    Node *p = head;
    while (head)
    {                      
        head = head->next; 
        delete p;          
        p = head;          
    }
}

Node* LinkedList:: mid(){
    Node *slow = head;
    Node *fast = head;
    if(head == NULL) return NULL; // if the list is empty
    while(fast && fast->next){
        slow = slow->next; // move slow pointer by one step
        fast = fast->next->next; // move fast pointer by two steps
    }
    return slow; // when fast pointer reaches the end, slow pointer will be at the middle
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);
    l.Display();
    Node* midNode = l.mid();
    if(midNode) {
        cout << "Middle element: " << midNode->data << endl;
    } else {
        cout << "List is empty, no middle element." << endl;
    }
    return 0;
}