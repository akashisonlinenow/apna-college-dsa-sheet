//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below method */
    long dp[1000][1000];
    long helper(string str, int i, int j)
    {
        if (dp[i][j] != -1)
        { // if that block of dp matrix is not -1 means dp is applied (not compulsory)
            return dp[i][j];
        }

        if (i > j)
            return 0;

        int mod = (int)pow(10, 9) + 7;
        if (i == j)
            return dp[i][j] = 1;

        else if (str[i] == str[j])
        {
            return dp[i][j] = (1 + helper(str, i + 1, j) + helper(str, i, j - 1)) % mod;
        }
        else
        {
            return dp[i][j] = (helper(str, i + 1, j) + helper(str, i, j - 1) - helper(str, i + 1, j - 1)) % mod;
        }
    }

    long long int countPS(string str)
    {
        int n = str.length();
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                dp[i][j] = -1; // initiallizing dp matrix as -1 initially
            }
        }

        return helper(str, 0, n - 1);

        // Your code here
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends