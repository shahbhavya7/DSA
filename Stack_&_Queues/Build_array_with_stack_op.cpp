#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>arr;
        int flag = 0;
        for(int i=1;i<=n && flag<target.size();i++){
            if(target[flag]==i){
                arr.push_back("Push");
                flag++;
            }
            else{
                arr.push_back("Push");
                arr.push_back("Pop");
            }
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1, 3};
    int n = 3;
    vector<string> result = sol.buildArray(target, n);
    
    for (const string& action : result) {
        cout << action << " ";
    }
    cout << endl;

    return 0;
}