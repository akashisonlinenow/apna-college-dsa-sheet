class Solution
{
public:
    int search(vector<int> &a, int target)
    {
        // for(int i=0; i<nums.size(); i++){    //O(N)
        //     if(nums[i]==target)
        //         return i;

        // }
        // return -1;

        int low = 0, high = a.size() - 1; // O(logN)
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == target)
                return mid;

            if (a[low] <= a[mid])
            {
                if (target >= a[low] && target <= a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target <= a[high] && target >= a[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};