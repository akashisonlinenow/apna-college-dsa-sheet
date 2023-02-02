//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        // int maxCount = 0;                            O(Nsquare) = T.C
        // int index = -1; // sentinels
        // for (int i = 0; i < n; i++) {
        //     int count = 0;
        //     for (int j = 0; j < n; j++) {
        //         if (arr[i] == arr[j])
        //             count++;
        //     }

        //     // update maxCount if count of
        //     // current element is greater
        //     if (count > maxCount) {
        //         maxCount = count;
        //         index = i;
        //     }
        // }

        // // if maxCount is greater than n/2
        // // return the corresponding element
        // if (maxCount > n / 2)
        //     return arr[index];

        // else
        //     return -1;

        int ele = 0;                     // Moores voting algorithm
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                ele = arr[i];
            }
            if (ele == arr[i])
                count++;
            else
                count--;
        }

        count = 0;
        for (int i = 0; i < n; i++)                               // checking that whether the count of ele obtained is greater than n/2                     
        {
            if (ele == arr[i])
                count++;
        }

        if (count > n / 2)
            return ele;

        return -1;
        // your code here
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
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
