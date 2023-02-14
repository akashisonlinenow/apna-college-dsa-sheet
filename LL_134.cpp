//{ Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

int length(Node *head)
{
    Node *temp = head;
    int l = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    int l1 = length(head1), l2 = length(head2); // refer from codefrekas and apna college

    Node *ptr1 = head1, *ptr2 = head2;

    while (ptr1 != 0)
    {
        ptr1 = ptr1->next;
        l1++;
    }

    while (ptr2 != 0)
    {
        ptr2 = ptr2->next;
        l2++;
    }

    if (l1 > l2)
    {
        for (int i = 0; i < l1 - l2; i++)
        {
            ptr1 = ptr1->next;
        }
    }
    else
    {
        for (int i = 0; i < l2 - l1; i++)
        {
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1->data;
    // Your Code Here
}
