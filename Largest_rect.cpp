#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        vector<int> largestRectangleArea(vector<int>& heights) {
        vector<int>mp;
        stack<int>st;
        for (int i = heights.size()-1; i >= 0; i--) {
  
            int num = heights[i];
            int width = 1;
            while(!st.empty() && st.top() < num){ // if stack is not empty and top is not 0 and top is less than num then pop
                st.pop();
            }
            if(st.empty()){
                int area = width * num;
                mp.push_back(area);
            }
            else{
                if(heights[i]<heights[i-1] && i>0){
                width = st.size()+1;
                int area = width * num;
                mp.push_back(area);
            }
            else{
                    width = st.size()+1;
                    int area = width * num;
                    mp.push_back(area);
                    for(int j = 0; j < st.size(); j++){
                        st.pop();
                    }
                }
            }
            st.push(num);
            
        }
        int ans = 0;
        for(int i = 0; i < mp.size(); i++){
            ans = max(ans, mp[i]);
        }
        return mp;
    }
};

int main(){
    //[2,1,5,6,2,3]
    vector<int>nums = {2,0,2};
    Solution s;
    // cout<<s.largestRectangleArea(nums)<<endl;
    vector<int>ans = s.largestRectangleArea(nums);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
  
    return 0;
}   