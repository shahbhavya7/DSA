#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int counter = 0; // Count fresh oranges
        int time = 0; // Time taken for all oranges to rot
        for(int i = 0; i < grid.size(); i++) { // Count fresh oranges
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    counter++;
                }
            }
        }
        // storing the rotten oranges in a queue
        queue<pair<int, int>> q; // pair as to store coordinates 
        for(int i = 0; i < grid.size(); i++) { // Iterate through the grid
            for (int j = 0; j < grid[0].size(); j++) { // grid[0].size() gives the number of columns of the grid
                if (grid[i][j] == 2) {
                    q.push({i, j}); // push rotten oranges into the queue
                }
            }
        }
        while(!q.empty() && counter > 0){
            for(int i = 0; i < q.size(); i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                // Check all four directions
                if (x > 0 && grid[x-1][y] == 1) { // Up
                    grid[x-1][y] = 2; // Rot the orange
                    counter--; // Decrease fresh orange count
                    q.push({x-1, y}); // Push new rotten orange to queue
                }
                if (x < grid.size() - 1 && grid[x+1][y] == 1) { // Down
                    grid[x+1][y] = 2;
                    counter--;
                    q.push({x+1, y});
                }
                if (y > 0 && grid[x][y-1] == 1) { // Left
                    grid[x][y-1] = 2;
                    counter--;
                    q.push({x, y-1});
                }
                if (y < grid[0].size() - 1 && grid[x][y+1] == 1) { // Right
                    grid[x][y+1] = 2;
                    counter--;
                    q.push({x, y+1});
                }
            }
            time++; // Increment time after processing all rotten oranges in the queue
        }
        // If there are still fresh oranges left, return -1
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1; // Fresh oranges left, return -1
                }
            }
        }
        return time;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,1},{0,1,2}};
    int result = sol.orangesRotting(grid);
    cout << "Time taken for all oranges to rot: " << result << " minutes" << endl;
    return 0;
}
