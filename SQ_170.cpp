//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    { // refer yogesh & shailesh utube  vv imp ques
        // Code here
        queue<pair<int, int>> q;
        int r = grid.size();    // row
        int c = grid[0].size(); // col

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                { // psuh all cell with 2
                    q.push({i, j});
                }
            }
        }

        int count = 0;
        q.push({-1, -1}); // dividation line
        while (!q.empty())
        {
            int i = q.front().first; // (i,j)
            int j = q.front().second;
            if (i == -1 && j == -1 && q.size() == 1)
            { // if only (-1,-1) present
                q.pop();
                break;
            }
            else if (i == -1 && j == -1 && q.size() > 1)
            { // if other cells with (-1,-1) is too present
                count++;
                q.pop();
                q.push({-1, -1});
            }
            else
            { // when cells with 2 is taken under consideration and rotting its neighbours
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
                if (i + 1 < r && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (j + 1 < c && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                q.pop();
            }
        }

        for (int i = 0; i < r; i++)
        { // after rotting everything if 1 is present return -1 as there is Example 2 in ques
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return count;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends