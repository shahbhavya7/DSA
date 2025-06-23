#include<bits/stdc++.h>
using namespace std;

class QueueStack {
public:
    queue<int> q; // Using a single queue to implement stack behavior
    QueueStack() {
    }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) {
            int front = q.front();
            q.pop();
            q.push(front); // Move the front element to the back
        }
    }
    
    int pop() {
        if (q.empty()) {
            return -1; // Stack is empty
        }
        int topElement = q.front();
        q.pop();
        return topElement; // Return the top element
    }
    
    int top() {
        if (q.empty()) {
            return -1; // Stack is empty
        }
        return q.front(); // Return the top element without removing it
    }
    
    bool isEmpty() {
        return q.empty(); // Check if the queue is empty
    }
};

int main(){
    QueueStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << endl; // Should print 30
    cout << stack.top() << endl; // Should print 20
    cout << stack.isEmpty() << endl; // Should print 0 (false)
    return 0;
}