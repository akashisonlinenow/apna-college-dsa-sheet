class Solution
{
public:
    void rotate(vector<vector<int>> &m)
    {
        int n = m.size(); // no. of rows and cols

        for (int i = 0; i < n; i++)
        { // transpose
            for (int j = 0; j < i; j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        { // reversing every rows
            reverse(m[i].begin(), m[i].end());
        }
    }
};