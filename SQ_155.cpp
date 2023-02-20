//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        queue<int> a = rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends

// function Template for C++

// Function to reverse the queue.

// void que_rev(queue<int> &q){             recurrsive approach
//     if(q.size()==0) return;

//     int ele = q.front();
//     q.pop();

//     que_rev(q);
//     q.push(ele);
// }
queue<int> rev(queue<int> q)
{
    // stack<int> st;                   // iterative approach
    // while(!q.empty()){
    //     st.push(q.front());
    //     q.pop();
    // }

    // queue<int> a;
    // while(st.empty()){
    //     a.push(st.top());
    //     st.pop();
    // }

    // return a;

    // using a stack to reverse the queue.
    stack<int> s;
    while (!q.empty())
    {
        // pushing elements from queue into stack and removing them from queue.
        s.push(q.front());
        q.pop();
    }
    // creating new queue.
    queue<int> a;
    while (!s.empty())
    {
        // now pushing elements back into the queue from stack and removing them
        // from stack. queue gets reversed as stack follows last in first out.
        a.push(s.top());
        s.pop();
    }
    // returning reversed queue.
    return a;

    // que_rev(q);
    // return q;

    // add code here.
}