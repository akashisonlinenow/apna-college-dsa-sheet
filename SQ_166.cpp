//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string s)
    { // refer yogesh&shailesh(codelibrary) utube
        vector<int> vis(26, 0);
        string ans;
        vector<char> v;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (vis[s[i] - 'a'] == 0)
            {
                v.push_back(s[i]);
            }
            vis[s[i] - 'a']++;
            int f = 0, m = v.size();
            for (int j = 0; j < m; j++)
            {
                if (vis[v[j] - 'a'] == 1)
                {
                    ans.push_back(v[j]);
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                ans.push_back('#');
        }
        return ans;
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
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends