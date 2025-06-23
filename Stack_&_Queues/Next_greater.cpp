#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//--Brute force (My approach)
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         map<int, int> mp;
//         for (int i = 0; i < nums2.size(); i++) {
//             mp[nums2[i]] = i; // store the index of each element in nums2
//         }
//         vector<int>ans;
//         for(int i = 0; i < nums1.size(); i++){ //
//             int pos = mp[nums1[i]];
//                 int j;
//                 for( j = pos+1; j < nums2.size(); j++){
//                     if(nums2[j]>nums1[i]){
//                         ans.push_back(nums2[j]);
//                         break;
//                     }
//                 }
//                 if(j==nums2.size()){
//                     ans.push_back(-1);
//                 }

//             }
//         return ans;
// }

//- Brute force 2
//  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> ans;
//     for(int i = 0; i < nums1.size(); i++){
//         int pos = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
//         int j;
//         for(j = pos+1; j < nums2.size(); j++){
//             if(nums2[j]>nums1[i]){
//                 ans.push_back(nums2[j]);
//                 break;
//             }
//         }
//         if(j==nums2.size()){
//             ans.push_back(-1);
//         }
//     }
//     return ans;
//  }

//- Optimal
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;
    
    // Process nums2 from right to left to find next greater elements
    for (int i = nums2.size() - 1; i >= 0; --i) {
        int num = nums2[i];
        // Pop elements from the stack that are less than or equal to current num
        while (!st.empty() && st.top() <= num) {
            st.pop();
        }
        // If stack is empty, no greater element exists
        if (st.empty()) {
            nextGreater[num] = -1;
        } else {
            nextGreater[num] = st.top();
        }
        // Push current num onto the stack
        st.push(num);
    }
    
    // Build the result for nums1 using the map
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }
    
    return result;
}
};

int main(){
    Solution s;
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}