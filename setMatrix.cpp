#include <bits/stdc++.h>
using namespace std;

void setZeroes_I(vector<vector<int>> &matrix)
{ // brute force
    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns
    vector<vector<int>> visited = matrix;
    for (int i = 0; i < n; i++) // capturing row with zero
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    visited[i][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)  // capturing cols with zero
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    visited[k][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = visited[i][j];
        }
    }
}



int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes_I(matrix);
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}