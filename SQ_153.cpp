//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                st.push(s[i] - '0');
            }
            else
            {
                int a1 = st.top();
                st.pop();
                int a2 = st.top();
                st.pop();

                switch (s[i])
                {

                case '*':
                    st.push(a2 * a1);
                    break;

                case '/':
                    st.push(a2 / a1);
                    break;

                case '+':
                    st.push(a2 + a1);
                    break;

                case '-':
                    st.push(a2 - a1);
                    break;
                }
            }
        }
        return st.top();
        // Your code here
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}

// } Driver Code Ends