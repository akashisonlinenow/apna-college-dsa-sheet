// counting sort

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
    string countSort(string s)
    {
        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++)
        { // preparing count array
            count[s[i] - 'a']++;
        }

        for (int i = 1; i < 26; i++)
        { // prefix sum of count array
            count[i] += count[i - 1];
        }

        string ans(s.size(), ' '); // ans string declaration
        for (int i = 0; i < s.size(); i++)
        { // iterating through given string and seeing in count arr its sorted pos and placing it in ans arr
            int x = --count[s[i] - 'a'];
            ans[x] = s[i];
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
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        Solution obj;
        cout << obj.countSort(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends