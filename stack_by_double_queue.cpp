#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2; // Two queues to implement stack behavior
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x); // Push the new element onto q1
    }
    
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front()); // Move all but the last element to q2
            q1.pop();
        }
        int topElement = q1.front(); // Get the last element (top of the stack)
        q1.pop(); // Remove the last element from q1
        swap(q1, q2); // Swap q1 and q2 to maintain the stack order
        return topElement; // Return the popped element
    }
    
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front()); // Move all but the last element to q2
            q1.pop();
        }
        int topElement = q1.front(); // Get the last element (top of the stack)
        q2.push(q1.front()); // Push it to q2 to maintain the stack order
        q1.pop(); // Remove the last element from q1
        swap(q1, q2); // Swap q1 and q2 to maintain the stack order
        return topElement; // Return the top element
    }
    
    bool empty() {
        return q1.empty(); // Check if the stack is empty
    }
};

int main(){
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << endl; // Should print 30
    cout << stack.pop() << endl; // Should print 20
    return 0;
}