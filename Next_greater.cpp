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
    vector<int> ans;
    stack<int> st;
    for (int i = nums2.size()-1; i >=0 ; i--) {
        int element = nums2[i];

        if(st.empty()){
            st.push(element);
            ans.push_back(-1);
            continue;
        }
        // if stack top is greater than element
        if(st.top()>element){
            st.push(element);
            ans.push_back(st.top());
            continue;
        }
        // if stack top is less than element keep removing elements from stack untill stack top is greater than element
        while(!st.empty() && st.top()<=element){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(element); // push the current element to the stack after popping all elements greater than it
    }
    return ans;
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