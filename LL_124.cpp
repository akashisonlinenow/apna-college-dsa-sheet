/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // ListNode* prevptr = NULL;          Iterative method...
        // ListNode* currptr = head;
        // ListNode* nextptr;

        // while(currptr!=NULL){
        //     nextptr = currptr->next;
        //     currptr->next = prevptr;

        //     prevptr = currptr;
        //     currptr = nextptr;

        // }
        // return prevptr;

        if (head == NULL || head->next == NULL)
        { // recurssive method...
            return head;
        }

        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;
    }
};