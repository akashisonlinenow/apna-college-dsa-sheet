//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // int ans = 0;              Brute force O(Nsquare)=T.C

        // // Fix the first element as A[i]
        //     for (int i = 0; i < n - 2; i++) {
        //         // Fix the second element as A[j]
        //         for (int j = i + 1; j < n - 1; j++) {
        //             // Now look for the third number
        //             for (int k = j + 1; k < n; k++)
        //                 if (arr[i] + arr[j] + arr[k] < sum)
        //                     ans++;
        //         }
        //     }
        //     return ans;
        // Your code goes here

        sort(arr, arr + n); // T.c = O(Nsquare)
        int ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                if (arr[i] + arr[j] + arr[k] >= sum)
                    k--;
                else
                {
                    ans += (k - j);
                    j++;
                }
            }
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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends