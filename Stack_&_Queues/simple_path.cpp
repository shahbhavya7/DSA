#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string dir;
        while (getline(ss, dir, '/')) { // getline splits the string by '/' , it takes three arguments: the input stream, the string to store the result, and 
            // the delimiter , delimiter helps to split the string by '/'. input stream stores the path, and the string to store the result is 'dir'.
            if (dir.empty() || dir == ".") { // If the directory is empty or is a single dot, we skip it.
                continue;
            } else if (dir == "..") { // If the directory is a double dot, we pop the top element from the stack if it is not empty.
                if (!s.empty()) {
                    s.pop();
                }
            } else { // If the directory is a valid name, we push it onto the stack.
                s.push(dir);
            }
        }
        string res;
        while (!s.empty()) { // We construct the result by popping elements from the stack.
            res = "/" + s.top() + res; // at each step we put a '/' before the directory name and concatenate it to the result.
            // res it added after the directory name to ensure the correct order as stack stores directories in reverse order.
            s.pop();
        }
        return res.empty() ? "/" : res; // If the result is empty, we return "/", otherwise we return the constructed path.
    } 
};


int main(){
    Solution sol;
    string path = "/home/user/Documents/../Pictures";
    cout << sol.simplifyPath(path) << endl; // Output: "/c"
    return 0;
}