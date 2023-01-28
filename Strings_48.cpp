class Solution
{
public:
    int characterReplacement(string s, int k)
    { // sliding window variable type
        int n = s.size();
        int i = 0, j = 0, mx = 0;
        unordered_map<char, int> mp;
        int ans = INT_MIN;
        while (j < n)
        {
            mp[s[j]]++;
            mx = max(mx, mp[s[j]]);
            if ((j - i + 1) - mx > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);

            j++;
        }
        return ans;
    }
};