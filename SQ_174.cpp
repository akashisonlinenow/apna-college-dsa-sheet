//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Returns sum of two numbers formed
    // from all digits in a[]
    long long int minSum(int arr[], int n)
    {
        // min Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // to store the 2 numbers formed by array elements to
        // minimize the required sum
        long long int a = 0, b = 0;

        // Adding elements in Priority Queue
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);

        // checking if the priority queue is non empty
        while (!pq.empty())
        {
            a *= 10;
            a += pq.top();
            pq.pop();
            if (!pq.empty())
            {
                b *= 10;
                b += pq.top();
                pq.pop();
            }
        }
        return a + b;
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
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minSum(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends