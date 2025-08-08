#include <bits/stdc++.h>
using namespace std;

void merge_I(vector<int> &nums1, int m, vector<int> &nums2, int n) // Brute Force
{
    vector<int>merged;
    for(int i = 0; i < m; i++)
    {
        merged.push_back(nums1[i]);
    }
    for(int i = 0; i < n; i++)
    {
        merged.push_back(nums2[i]);
    }
    sort(merged.begin(), merged.end());
    for (int i = 0; i < m+n; i++) {
        nums1[i] = merged[i];
    }
}

void merge_II(vector<int> &nums1, int m, vector<int> &nums2, int n) // Brute Force 2
{
    for(int i = 0; i < n; i++)
    {
        nums1[m+i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());

}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    merge_II(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}