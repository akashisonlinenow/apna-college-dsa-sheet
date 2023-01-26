#include <bits/stdc++.h>

int findMinOps(int arr[], int n) // two pointer approach
{
    int ans = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }

        else if (arr[i] < arr[j])
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }

        else
        {
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }
        return ans;
        /* code */
    }

    int main()
    {
        int arr[] = {11, 14, 15, 99};
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << findMinOps(arr, n) << "\n";
        return 0;
    }
}