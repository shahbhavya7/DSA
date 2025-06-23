#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  vector<int> nextSmallerElement(vector<int>& nums) {
    vector<int> nextSmaller;
    stack<int> st;
    
    // Process nums2 from right to left to find next greater elements
    for (int i = nums.size() - 1; i >= 0; --i) {
        int num = nums[i];
        // Pop elements from the stack that are less than or equal to current num
        while (!st.empty() && st.top() >= num) {
            st.pop();
        }
        // If stack is empty, no greater element exists
        if (st.empty()) {
            nextSmaller.push_back(-1);
        } else {
            nextSmaller.push_back(st.top());
        }
        // Push current num onto the stack
        st.push(num);
    }
    reverse(nextSmaller.begin(), nextSmaller.end());
    return nextSmaller;
}
};



int main(){
    Solution s;
    vector<int> nums = {13, 7, 6, 12};
    vector<int> ans = s.nextSmallerElement(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}