//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string removeConsecutiveCharacter(string s)
    {
        int n = s.length();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && s.at(i) == s.at(i + 1))
            {
                continue;
            }
            else
                res = res + s.at(i);
        }
        return res;
        // code here.
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends