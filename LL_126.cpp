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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // in function heads of both given ll list1 list2 are passed as parameter. and we have to return the head of merged ll.
        // fh will store the address of the first node of the final ll.
        // ft will always store the address of the last node of the final ll

        ListNode *fh = NULL, *ft = NULL; // initially point it to null

        while (list1 != NULL && list2 != NULL)
        {                                 // when head1 or head2 anyone become not equal to nul
            if (fh == NULL && ft == NULL) // at initial when fh and ft is null pointed
            {
                if (list1->val > list2->val)
                { // if head2 is small then assign it to fh and ft and move head2 forward
                    fh = list2;
                    ft = list2;
                    list2 = list2->next;
                }
                else
                { // if head1 is small then assign it to fh and ft and move head1 forward
                    fh = list1;
                    ft = list1;
                    list1 = list1->next;
                }
            }
            // when fh and ft remains not null 👇
            if (list1->val < list2->val)
            {
                ft->next = list1;
                ft = ft->next;
                list1 = list1->next;
            }
            else
            {
                ft->next = list2;
                ft = ft->next;
                list2 = list2->next;
            }
        }

        // when iteration reach till end then...
        if (list1 != NULL)
        { // when head2 points null but head1 not
            ft->next = list1;
        }

        if (list2 != NULL)
        { // when head1 points null but head2 not
            ft->next = list2;
        }

        return fh; // returning head of the merged ll...
    }
};