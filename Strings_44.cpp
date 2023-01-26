class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";

        string ans = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string second = strs[n - 1];

        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] == second[i])
                ans = ans + first[i];
            else
                break;
        }
        return ans;
    }
};