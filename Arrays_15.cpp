class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // int n = nums.size();   // O(n^2)
        // for(int i=0; i<n;i++){
        //     int e = nums[i];
        //     for(int j=i+1;j<n;j++){
        //         if(e==nums[j])
        //         return true;
        //     }
        // }
        // return false;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};