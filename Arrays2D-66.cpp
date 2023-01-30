class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();    // no. of rows
        int col = matrix[0].size(); // no. of cols
        vector<int> list;
        if (row == 0) // if matrix is empty
            return list;

        int l = 0, r = col - 1;
        int t = 0, b = row - 1;
        int d = 0;

        while (l <= r && t <= b)
        { // loop till when l goes ahed of r or t goes behing b
            if (d == 0)
            { // for direction = 0
                for (int i = l; i <= r; i++)
                {
                    list.push_back(matrix[t][i]);
                }

                d = 1;
                t++;
            }
            else if (d == 1)
            { // for direction = 1
                for (int i = t; i <= b; i++)
                {
                    list.push_back(matrix[i][r]);
                }

                d = 2;
                r--;
            }
            else if (d == 2)
            { // for direction = 2
                for (int i = r; i >= l; i--)
                {
                    list.push_back(matrix[b][i]);
                }

                d = 3;
                b--;
            }
            else if (d == 3)
            { // for direction = 3
                for (int i = b; i >= t; i--)
                {
                    list.push_back(matrix[i][l]);
                }

                d = 0;
                l++;
            }
        }

        return list;
    }
};