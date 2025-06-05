#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
    int MAX_SIZE = 1000;
    int topIndex = -1;
    int arr[1000];
public:
    ArrayStack() {
    }
    
    void push(int x) {
        if(topIndex == MAX_SIZE -1){
            cout << "Stack Overflow" << endl;
            return;
        }
        else{
            topIndex++;
            arr[topIndex] = x;
        }
    }
    
    int pop() {
        if(topIndex == -1){
            return -1;
        }
        else{
            int x = arr[topIndex];
            topIndex--;
            return x;
        }
    }
    
    int top() {
        if(topIndex == -1){
            return -1;
        }
        else{
            return arr[topIndex];
        }
    }
    
    bool isEmpty() {
        if(topIndex == -1) return true;
    }
};




int main(){
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.isEmpty() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.isEmpty() << endl;
    return 0;
}