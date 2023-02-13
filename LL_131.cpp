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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(); // creating dummy node which will point to head node
        dummy->next = head;
        ListNode *slow = dummy; // slow and fast node whuch first point to dummy
        ListNode *fast = dummy;

        for (int i = 1; i <= n; i++)
        { // take fast till nth node which is given as input
            fast = fast->next;
        }

        while (fast->next != NULL)
        { // then after that iterate both fast and slow together by 1 node ahead till fast reaches last node
            slow = slow->next;
            fast = fast->next;
        }

        // ListNode *temp = slow->next;
        slow->next = slow->next->next; // deleting the node next to the slow node and pointer break and change
        // free(temp);

        return dummy->next;
    }
};