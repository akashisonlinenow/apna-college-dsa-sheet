class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;                // for storing ans
        unordered_map<string, vector<string>> ump; // for storing in format of key:value = word:its anagram

        for (auto it : strs)
        {
            string temp = it; // temp is temporary var for storing iterator and then it pushed to ump
            sort(it.begin(), it.end());
            ump[it].push_back(temp);
        }

        for (auto it : ump)
        {
            vector<string> temp = it.second; // all anagrams are grouped and is stored in temp
            ans.push_back(temp);             // temp is pushed to ans
        }
        return ans;
    }
};