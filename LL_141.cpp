//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
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

// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *temp = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node *getmid(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reorderList(Node *head)
    { // refer codefreaks utube
        Node *l1 = head;
        Node *mid = getmid(head);
        Node *l2 = mid->next;
        l2 = reverse(l2);

        mid->next = NULL;

        Node *ans = new Node(-1);
        Node *curr = ans;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
            {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            if (l1 != NULL)
            {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        head = ans->next;
        // Your code here
    }
};

//{ Driver Code Starts.

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    int t, n, m, i, x;

    cin >> t;
    while (t--)
    {
        struct Node *temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        Solution ob;

        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends