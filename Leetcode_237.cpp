// somewhat similar to LL_127.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (node->next == NULL)
        { // given node is tail node
            *node = NULL;
        }
        else
        {
            node->val = node->next->val;   // copying next node of given node value to given node
            node->next = node->next->next; // given node poining to next of next node
        }
    }
};