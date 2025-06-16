#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int largestRectangleArea(vector<int> &heights)
    // {
    //     vector<int> mp;
    //     stack<int> st;
    //     int width  = st.size() + 1;
    //     for (int i = heights.size() - 1; i >= 0; i--)
    //     {
    //         if (!st.empty() && st.top() < heights[i])
    //         {   
    //             int num = heights[i];
    //             while (!st.empty() && st.top() < num)
    //             {
    //                 st.pop();
    //                 width = 1;
    //             }
    //             int area = width * num;
    //             mp.push_back(area);
    //             st.push(num);
    //         }
    //         else
    //         {
    //             if (st.empty())
    //             {
    //                 int area = width * heights[i];
    //                 mp.push_back(area);
    //             }
    //             else
    //             {
    //                 width = st.size() + 1;
    //                 int area = width * heights[i];
    //                 mp.push_back(area);
    //             }
    //             st.push(heights[i]);
    //         }
    //     }
    //     int ans = 0;
    //     for (int i = 0; i < mp.size(); i++)
    //     {
    //         ans = max(ans, mp[i]);
    //     }
    //     return ans;
    // }
};

int main()
{
    //[2,1,5,6,2,3]
    vector<int> nums = {2,1,5,6,2,3};
    Solution s;
    // cout<<s.largestRectangleArea(nums)<<endl;

    return 0;
}