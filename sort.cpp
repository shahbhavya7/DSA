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
    Node* sort();
   
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

// Node* LinkedList::sort() //- This is Brute Force Approach
// {
//     Node *p = head, *q = NULL, *temp;
//     int tempData;

//     if (head == NULL) return head; // If the list is empty

//     while (p != NULL)
//     {
//         q = p->next;
//         while (q != NULL)
//         {
//             if (p->data > q->data)
//             {
                // Swap data
//                 tempData = p->data;
//                 p->data = q->data;
//                 q->data = tempData;
//             }
//             q = q->next;
//         }
//         p = p->next;
//     }
//     return head; // Return the sorted list
// }

Node* LinkedList::sort(){ //- This is Better Approach
    Node *p  = head;
    vector<int> arr;
    while (p) {
        arr.push_back(p->data);
        p = p->next;
    }
    std::sort(arr.begin(), arr.end()); // Sort the array using STL sort
    Node *temp = head;
    for (int i = 0; i < arr.size(); i++) {
        temp->data = arr[i]; // Update the linked list with sorted values
        temp = temp->next;
    }
    return head; // Return the sorted list
}

int main(){
    int A[] = {5, 3, 8, 1, 2};
    LinkedList l(A, 5);
    cout << "Original List: ";
    l.Display();
    l.sort();
    cout << "Sorted List: ";
    l.Display();
    return 0;
}