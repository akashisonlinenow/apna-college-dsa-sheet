//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

Node *mergeTwoLists(Node *a, Node *b)
{                             // a is head of first list b is head another list
    Node *temp = new Node(0); // dummy node
    Node *res = temp;

    while (a != NULL && b != NULL)
    { // loop goes till from a or b anyone becomes null
        if (a->data < b->data)
        { // if 'a' value is less then include that in dummy
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        { // if 'b' value is less then include that in dummy
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
    { // if 'b' exhausts and 'a' is remaining then push all values remaining of 'a' as it is
        temp->bottom = a;
    }
    else
    { //  if 'a' exhausts and 'b' is remaining then push all values remaining of 'b' as it is
        temp->bottom = b;
    }
    return res->bottom; // res will point to temp and res ka bottom is the head flattened list
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    // recur for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return root
    // it will be in turn merged with its left
    return root;
    // Your code here
}
