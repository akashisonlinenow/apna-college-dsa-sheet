class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) // searching and sorting questions
    {
        unordered_map<int, int> ump;

        for (auto it : target)
        {
            if (ump.find(it) != ump.end())
            {
                ump[it]++;
            }
            else
                ump.insert({it, 1});
        }

        for (auto it : arr)
        {
            if (ump.find(it) != ump.end() && ump[it] > 0)
            {
                ump[it]--;
            }
            else
                return false;
        }
        return true;
    }
};