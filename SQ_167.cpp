//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &m, int n) // refer to yogesh & shailesh utube...
    {
        // int in[n] = {0};         // tc = O(n2) sc=O(n)
        // int out[n] = {0};  // in -> how much people knows i and out -> how much 'i' knows

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(m[i][j]==1){ // m[i][j] = 1 means person i knows j
        //             in[j]++;
        //             out[i]++;
        //         }
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(in[i]==n-1 && out[i]==0){  // if i is known by everone except i itself so n-1 but i dont know anyone so out[i]=0
        //         return i;  // then i is celebrity
        //     }
        // }
        // return -1;   /// if no celebrity found
        // code here

        // tc O(n), sc = O(1)
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (m[c][i] == 1)
            {
                c = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != c && (m[c][i] == 1 || m[i][c] == 0))
            {
                return -1;
            }
        }
        return c;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends