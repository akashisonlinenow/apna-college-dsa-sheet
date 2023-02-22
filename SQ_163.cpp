//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int n, vector<int> &ip, vector<int> &op)
    {
        stack<int> st; // refer study with saumya utube
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            st.push(ip[i]);

            while (!st.empty() && st.top() == op[j])
            {
                st.pop();
                j++;
            }
        }

        if (st.size() == 0)
            return 1;

        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends