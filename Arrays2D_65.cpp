class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    { // S.C. = O(1)

        int m = matrix.size();
        int n = matrix[0].size();
        int x = 1;
        int y = 1;

        for (int j = 0; j < n; j++) // step 1
        {
            if (matrix[0][j] == 0)
                x = 0;
        }

        for (int i = 0; i < m; i++) // step 2
        {
            if (matrix[i][0] == 0)
                y = 0;
        }

        for (int i = 1; i < m; i++) //  step 3
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int j = 1; j < n; j++) //   step 4
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }

        for (int i = 1; i < m; i++) // step 5
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        if (y == 0) //   step 6
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }

        if (x == 0) //   Step 6
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // These steps are detaily explained on notebook DMW
    }
};