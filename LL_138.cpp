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
class Solution // dummy_rightGreater_deletion algorithm (name given by me)
{
public: // here dont just see imediate right node. U must see all the right nodes
    // step 1. reverse the ll
    // step 2. traverse the ll, keep track of max value observed so far

    Node *Reverse(Node *head)
    {
        struct Node *prev, *curr, *nxt;
        prev = NULL;
        curr = head;
        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        struct Node *newhead = Reverse(head); // newhead is the pointer pointing to new head of the reversed list
        struct Node *p;
        p = newhead; // p is a pointer which points to newhead initially and moves forward

        int max_so_far = INT_MIN;
        struct Node *dummy = (struct Node *)malloc(sizeof(struct Node)); // a new dummy node creation
        struct Node *d = dummy;                                          // d is the node which point to dummy

        while (p != NULL)
        {
            if (p->data >= max_so_far)
            {
                max_so_far = p->data;
                d->next = p;
                d = d->next;
            }
            p = p->next; // moving pointer forward
        }
        d->next = NULL; // after p pointing to null make d (which is pointing to dummy) too point to null
        struct Node *result = Reverse(dummy->next);

        return result;
        // your code goes here
    }
};

//{ Driver Code Starts.

int main()
{
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
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends