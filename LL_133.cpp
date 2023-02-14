//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes

        // Floyd's cycle detection and removal algorithm...   V V V IMP
        // refer to ayushi sharma utube.

        if (head == NULL && head->next == NULL)
        { // if there is no node or only one node present
            return;
        }

        Node *slow = head;
        Node *fast = head;

        slow = slow->next;       // slow move by one step
        fast = fast->next->next; // fast move by two steps

        while (fast != NULL && fast->next != NULL)
        {
            if (slow == fast)
                break;
            // move slow by 1 step and fast by 2 untill slow = fast i.e cycle detected
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == fast)
        {
            slow = head; // point slow to head

            if (slow == fast)
            { // special condition - after cycle detection slow and fast both come in head
                while (fast->next != slow)
                {
                    fast->next = NULL;
                }
            }

            else
            { // in other all condition except special
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                fast->next = NULL;
                return;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends