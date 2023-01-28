class Solution
{
public:
    string longestPalindrome(string s) // dp approach...    VVVVVVVVVV IMP... see utube video of "code with alisha"
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // initializing a dp matrix
        int max_len = 0;
        string ans; // ans is to be returned which is output

        for (int diff = 0; diff < n; diff++)
        {
            for (int i = 0, j = i + diff; j < n; i++, j++)
            {
                if (i == j)
                { // computing all diagonal elements
                    dp[i][j] = 1;
                }
                else if (diff == 1)
                { // computing all elements whose diff =1
                    // dp[i][j]=(s[i]==s[j])?2:0;
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 0;
                }
                else
                { // computing all elements whose diff>1
                    if (s[i] == s[j] && dp[i + 1][j - 1] != 0)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (dp[i][j] != 0)
                { // if palindrome we obtained is not null.
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;        // j-i+1 is length of palindrome string
                        ans = s.substr(i, max_len); // it returns a substring from index i to j-i+1
                    }
                }
            }
        }
        return ans;

        //
    }
};