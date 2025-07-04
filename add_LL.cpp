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
    Node *add();

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

Node* LinkedList::add(){
    Node *dummy = new Node;
    Node *temp  = dummy;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry){ // Continue until both lists are exhausted and no carry remains, no carry meand carry is 0
        int sum = 0;
        if(head1 != NULL){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry; // Add carry from previous addition
        carry = sum / 10; // Calculate new carry for next addition, division will floor the value as it is integer division
        Node *newNode = new Node;
        newNode->data = sum % 10;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    return dummy->next; // Return the next of dummy node which is the head of the result list
}

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};
    LinkedList list1(A, 5);
    LinkedList list2(B, 5);
    list1.head1 = list1.getHead();
    list2.head2 = list2.getHead();
    LinkedList resultList;
    resultList.head1 = list1.head1;
    resultList.head2 = list2.head2;
    Node *resultHead = resultList.add();
    cout << "Result of addition: ";
    resultList.Display(resultHead);
    


 
    
    return 0;
}