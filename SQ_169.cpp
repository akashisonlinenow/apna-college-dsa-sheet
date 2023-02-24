//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    { // refer to codefreaks utube...
        queue<pair<int, int>> q;
        vector<vector<int>> grid2 = grid;

        int r = grid.size(), c = grid[0].size();
        int level = 0;
        int rtemp, ctemp, size;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            ++level;
            size = q.size();

            while ((size--) > 0)
            {
                rtemp = q.front().first;
                ctemp = q.front().second;
                q.pop();

                if (rtemp > 0 && grid[rtemp - 1][ctemp] == 0)
                {
                    q.push({rtemp - 1, ctemp});
                    grid[rtemp - 1][ctemp] = level;
                }
                if (ctemp > 0 && grid[rtemp][ctemp - 1] == 0)
                {
                    q.push({rtemp, ctemp - 1});
                    grid[rtemp][ctemp - 1] = level;
                }
                if (rtemp < r - 1 && grid[rtemp + 1][ctemp] == 0)
                {
                    q.push({rtemp + 1, ctemp});
                    grid[rtemp + 1][ctemp] = level;
                }
                if (ctemp < c - 1 && grid[rtemp][ctemp + 1] == 0)
                {
                    q.push({rtemp, ctemp + 1});
                    grid[rtemp][ctemp + 1] = level;
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid2[i][j] == 1)
                {
                    grid[i][j] = 0;
                }
            }
        }
        return grid;
        // Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends