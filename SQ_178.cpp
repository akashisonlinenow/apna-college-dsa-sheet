//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {
        // int sum1=0,sum2=0,sum3=0;  // refer yogesh & shailesh utube...
        // for(int i=0;i<n1;i++) sum1+=s1[i];
        // for(int i=0;i<n2;i++) sum2+=s2[i];
        // for(int i=0;i<n3;i++) sum3+=s3[i];

        // int top1=0,top2=0,top3=0;
        // int ans=0;

        // while(true){
        //     if(top1==n1 || top2==n2 || top3==n3){
        //         ans=0;
        //         break;
        //     }
        //     if(sum1==sum2 && sum2==sum3){
        //         ans=sum1;
        //         break;
        //     }
        //     if(sum1>=sum2 && sum1>=sum3){
        //         sum1 -= s1[top1++];
        //         // top1++;
        //     }
        //     if(sum2>=sum1 && sum2>=sum3){
        //         sum2 -= s2[top2++];
        //         // top2++;
        //     }
        //     if(sum3>=sum1 && sum3>=sum2){
        //         sum3 -= s3[top3++];
        //         // top3++;
        //     }
        // }
        // return ans;

        int i = 0; // referred by zlozie code utube ....
        int j = 0;
        int k = 0;

        int c1 = 0;
        for (int i = 0; i < N1; i++)
        {
            c1 += S1[i];
        }
        int c2 = 0;
        for (int i = 0; i < N2; i++)
        {
            c2 += S2[i];
        }
        int c3 = 0;
        for (int i = 0; i < N3; i++)
        {
            c3 += S3[i];
        }

        while (i < N1 && j < N2 && k < N3)
        {

            if (c1 == c2 && c2 == c3)
            {
                return c1;
            }

            else if (c1 > c2 || c1 > c3)
            {
                c1 -= S1[i];
                i++;
            }

            else if (c2 > c1 || c2 > c3)
            {
                c2 -= S2[j];
                j++;
            }

            else if (c3 > c2 || c3 > c1)
            {
                c3 -= S3[k];
                k++;
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for (int i = 0; i < n1; i++)
        {
            cin >> s1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> s2[i];
        }
        for (int i = 0; i < n3; i++)
        {
            cin >> s3[i];
        }
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends