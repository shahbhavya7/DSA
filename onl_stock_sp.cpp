#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s; // Stack to store pairs of price and index
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (s.empty()) {
            s.push({price, 1}); // If stack is empty, push the price with span 1
            return 1;
        }
        else{
            int span = 1;
            if (s.top().first <= price) { // If the top element's price is less than or equal to the current price
                while(!s.empty() && s.top().first <= price) { // pop elements from the stack while their price is less than or equal to the current price
                    span += s.top().second; // Add the span of the top element in each iteration
                    s.pop(); // Pop the top element
                } // at the end of this loop, span will contain the total span of the current price till the last element that is greater than the current price
            }
            s.push({price, span}); // Push the current price with its calculated span onto the stack 
            // the logic of pushing total span with current price is that if any new element comes in future with price gt than current price , then it will
            // also be gt other elements in the stack that were popped in the above loop, so we can use the span of current price to calculate the span of future elements
            // this way we can calculate the span of current price in O(1) time complexity
            return span;
        }
    }
};

int main(){
    StockSpanner stockSpanner;
    cout << stockSpanner.next(100) << endl; // Output: 1
    cout << stockSpanner.next(80) << endl;  // Output: 1
    cout << stockSpanner.next(60) << endl;  // Output: 1
    cout << stockSpanner.next(70) << endl;  // Output: 2
    cout << stockSpanner.next(60) << endl;  // Output: 1
    cout << stockSpanner.next(75) << endl;  // Output: 4
    cout << stockSpanner.next(85) << endl;  // Output: 6
    return 0;
}