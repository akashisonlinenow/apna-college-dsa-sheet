class Solution
{
public:
    int countSubstrings(string s)
    { // dp approach...    VVVVVVVVVV IMP... see utube video of "code with alisha"
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // initializing a dp matrix
        int ans = 0;                                        // ans is to be returned which is output

        for (int diff = 0; diff < n; diff++)
        {
            for (int i = 0, j = diff; j < n; i++, j++)
            {
                if (diff == 0)
                { // computing all diagonal elements
                    dp[i][j] = true;
                    ans++;
                }
                else if (diff == 1)
                { // computing all elements whose diff =1
                    if (s[i] == s[j])
                    { // if first and last character is same then that substring is palindrome
                        dp[i][j] = true;
                        ans++;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                { // computing all elements whose diff>1
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};