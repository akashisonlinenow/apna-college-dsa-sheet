//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
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

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        unordered_set<int> seen;

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            if (seen.find(curr->data) != seen.end())
            {                            // find func return an iterator of to be found value and if it is not equal to the end means we have that value in set initially
                prev->next = curr->next; // pointer break and point to the next ele of the duplicate ele
                free(curr);              // deleting that element
            }
            else
            {                            // no duplicate
                seen.insert(curr->data); // if not a duplicate then insert in the set
                prev = curr;             // move prev forward by assigning it to curr
            }
            curr = curr->next; // moving curr forward
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
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends