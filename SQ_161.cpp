//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxLength(string s)
    { // dp approach           // refer gfg practice utube..
        stack<int> st;
        st.push(-1); // this is first pushed with -1 bcoz for () this case we have to return length =2

        int ans = 0; // lenght

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            { // if ( then push its index to stack
                st.push(i);
            }
            else
            {                    // if ) then ...
                if (!st.empty()) // if stack is not empty then pop
                    st.pop();

                if (st.empty()) // if stack is empty then push the index of that bracket
                    st.push(i);
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends