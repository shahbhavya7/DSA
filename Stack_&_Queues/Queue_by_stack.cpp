#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
 // Flag to indicate which stack is being used for pop/peek operations
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
       int popedval;
           while(!s1.empty()) {
               s2.push(s1.top());
               s1.pop();
           }
         popedval = s2.top();
            s2.pop();
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
           return popedval;

    }
    
    int peek() {
        int peekedval;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        peekedval = s2.top();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return peekedval;
    }
    
    bool empty() {
        return s1.empty() && s2.empty(); // Check if both stacks are empty
    }
};

int main(){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl; // Should print 1
    cout << queue.pop() << endl;  // Should print 1
 
    return 0;
}