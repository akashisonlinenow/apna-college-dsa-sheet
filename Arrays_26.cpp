// We will run a for loop from 0 to N-1, to find out the pivot point.
// Set the left pointer(l)
// to the smallest value and the right pointer(r)
// to the highest value.To restrict the circular movement within the array
//  we will apply the modulo operation by the size of the array.
//  While l ! = r, we shall keep checking if arr[l] + arr[r] = sum.
//  If arr[l] + arr[r] is greater than X, update r = (N + r - 1) % N.
//  If arr[l] + arr[r] is less than X, update l = (l + 1) % N.
//  If arr[l] + arr[r] is equal to the value X, then return true.
//  If no such pair is found after the iteration is complete, return false.

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// This function returns true if arr[0..n-1]
// has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
    // Find the pivot element
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;

    // l is now index of smallest element
    int l = (i + 1) % n;

    // r is now index of largest element
    int r = i;

    // Keep moving either l or r till they meet
    while (l != r)
    {

        // If we find a pair with sum x,
        // we return true
        if (arr[l] + arr[r] == x)
            return true;

        // If current pair sum is less,
        // move to the higher sum
        if (arr[l] + arr[r] < x)
            l = (l + 1) % n;

        // Move to the lower sum side
        else
            r = (n + r - 1) % n;
    }
    return false;
}

// Driver code
int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int X = 16;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (pairInSortedRotated(arr, N, X))
        cout << "true";
    else
        cout << "false";

    return 0;
}
