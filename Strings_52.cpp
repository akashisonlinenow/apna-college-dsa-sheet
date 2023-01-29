//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr) // code with alisha utube
    {
        int infpt = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
            {
                infpt = i;
                break;
            }
        }
        if (infpt == 0)
        {
            sort(arr.begin(), arr.end());
        }
        else
        {
            int toswap = arr[infpt - 1];
            int min = INT_MAX;
            for (int j = infpt; j < n; j++)
            {
                if (arr[j] - toswap > 0 && arr[j] - toswap < min)
                {
                    int temp = arr[j];
                    arr[j] = arr[infpt - 1];
                    arr[infpt - 1] = temp;
                }
            }
            sort(arr.begin() + infpt, arr.end());
        }
        return arr;
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends