#include<bits/stdc++.h>
using namespace std;

class ArrayQueue {
public:
    int MAX_SIZE = 1000;
    int frontIndex = -1;
    int rearIndex = -1;
    int arr[1000];
    ArrayQueue() {
    }
    
    void push(int x) {
        if(rearIndex == MAX_SIZE - 1){
            cout<< "Queue Overflow" << endl;
            return;
        }
        else{
            rearIndex++;
            arr[rearIndex] = x;
        }
    }
    
    int pop() {
        if(frontIndex == rearIndex){
            return -1;
        }
        else{
            frontIndex++;
            int x = arr[frontIndex];
            return x;
        }
    }
    
    int peek() {
        if(frontIndex == rearIndex){
            return -1;
        }
        else{
            return arr[frontIndex + 1];
        }
    }
    
    bool isEmpty() {
        return (frontIndex == rearIndex);
    }
};

int main(){
    ArrayQueue queue;
    queue.push(10);
    queue.push(2);
    queue.push(3);
    cout << queue.pop() << endl;
    cout << queue.peek() << endl;
    cout << queue.isEmpty() << endl;
    return 0;
}