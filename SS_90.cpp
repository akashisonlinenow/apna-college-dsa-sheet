class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int start = 0, end = nums.size() - 1;
        int cost = 0;

        while (start < end)
        {
            cost += (nums[end] - nums[start]);
            start++;
            end--;
        }
        return cost;
    }
};