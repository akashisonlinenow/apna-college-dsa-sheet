//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings

    static bool comparator(string s1, string s2)
    {
        string first = s1 + s2;
        string second = s2 + s1;
        for (int i = 0; i < first.size(); i++)
        {
            if (first[i] > second[i])
                return true;
            else if (second[i] > first[i])
                return false;
        }
        return false;
    }

    string printLargest(vector<string> &arr)
    {
        // code here
        int n = arr.size();
        string ans = "";
        sort(arr.begin(), arr.end(), comparator);
        for (int i = 0; i < n; i++)
        {
            ans.append(arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends