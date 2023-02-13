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
    void reorderList(ListNode *head)
    {
        // NOTE - here we have to reorder nodes not its values..
        if (head == NULL || head->next == NULL)
            return;

        ListNode *slow = head; // with the help of fast and slow ptr we found mid element and broke list into l1 = 1 to mid-1 and l2 = reversed form of (mid to n)
        ListNode *fast = head;
        ListNode *prev = head;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode *l1 = head;
        ListNode *l2 = reverse(slow); // reversing

        merge(l1, l2); // merging function

        // If have any query see vid of codebix utube channel
    }

    ListNode *reverse(ListNode *l2)
    {
        if (l2 == NULL)
            return NULL;

        ListNode *prev = NULL;
        ListNode *curr = l2;
        ListNode *nxt = l2->next;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        while (l2 != NULL)
        {
            ListNode *next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }
};