#include<bits/stdc++.h>
using namespace std;

// class MinStack { //- This is brute force approach with O(n) time complexity for pop operation
// public:
//     stack<int>st;
//     int min;
//     MinStack() {
//         min = INT_MAX;
//     }
    
//     void push(int val) {
//         if(val < min) {
//             min = val;
//         }
//         st.push(val);
//     }
    
//     void pop() {
//         int topValue = st.top();
//         st.pop();
//         if(topValue == min) {
//              Recalculate the minimum value
//             min = INT_MAX;
//             stack<int> temp = st;
//             while(!temp.empty()) {
//                 if(temp.top() < min) {
//                     min = temp.top();
//                 }
//                 temp.pop();
//             }
//         }
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return min;
//     }
// };


class MinStack { //- This is an optimized approach with O(1) time complexity for all operations
  // Using a stack to store pairs of (value, minimum) , value is the actual value and minimum is the minimum value at that point in the stack
  // that value can be actual value itself or the minimum value of the previous element in the stack
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int mins;
      if (st.empty()) {
        mins = x;
      } else {
        mins = min(st.top().second, x);
      }
      st.push({x,mins});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

int main(){
    MinStack M;
    M.push(-2);
    M.push(0);
    M.push(-3);
    cout << "Top element: " << M.top() << endl; // Should print -3
    cout << "Minimum element: " << M.getMin() << endl; // Should print 3
    M.pop();
    cout << "Top element after pop: " << M.top() << endl; // Should print 0
    cout << "Minimum element after pop: " << M.getMin() << endl; // Should print -2
    return 0;
}