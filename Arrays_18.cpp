class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) // if only one element is present simply return it...
            return;
        int i = 1;
        int lastInc = -1;
        while (i < n)
        { // through this we get rightmost peak value
            if (nums[i] > nums[i - 1])
                lastInc = i;
            i++;
        }

        if (lastInc == -1)
        { // if the order is descending then sorting the full array
            for (int i = 0; i < n / 2; i++)
            {
                swap(nums[i], nums[n - i - 1]);
            }
            return;
        }

        // Find element in the range (nums[lastInc-1] to nums[lastInc]) to the right
        int mn = nums[lastInc];
        int index = lastInc;
        for (int i = lastInc; i < n; i++)
        {
            if (nums[i] > nums[lastInc - 1] && nums[i] < nums[index])
                index = i;
        }
        swap(nums[lastInc - 1], nums[index]);
        sort(nums.begin() + lastInc, nums.end());
    }
};