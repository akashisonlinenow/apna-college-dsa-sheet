class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // int count[256]={0};                    O(N)
        // int l = 0;
        // int r = 0;
        // int ans = 0;
        // while(r<s.length()){
        //     count[s[r]]++;
        //     while(count[s[r]>1]){
        //         count[s[l]]--;
        //         l++;
        //     }
        //     ans = max(ans,r-l+1);
        //     r++;
        // }
        // return ans;

        int length = 0, maxlength = 0, j = 0; // hashmap approach    O(N)
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            length++;
            while (mp[s[i]] > 1)
            {
                mp[s[j++]]--;
                length--;
            }
            maxlength = max(maxlength, length);
        }
        return maxlength;
    }
};