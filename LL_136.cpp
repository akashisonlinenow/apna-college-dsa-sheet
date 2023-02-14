//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    Node *zigZag(Node *head) // coding simplified utube channel
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *p = head;
        bool flag = true;

        while (p->next != NULL)
        {
            if (flag == true)
            {
                if (p->data > p->next->data)
                {
                    int temp = p->data;
                    p->data = p->next->data;
                    p->next->data = temp;
                }
                flag = !flag;
            }
            else
            {
                if (p->data < p->next->data)
                {
                    int temp = p->data;
                    p->data = p->next->data;
                    p->next->data = temp;
                }
                flag = !flag;
            }

            p = p->next;
        }
        return head;
        // your code goes here
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *ans = ob.zigZag(head);
        print(ans);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends