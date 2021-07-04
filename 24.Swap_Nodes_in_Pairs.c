/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *start = NULL,*temp,*pre = head;
    if(head == NULL|| head->next == NULL)
        return head;
    start = head->next;
    while(head != NULL && head->next != NULL)
    {
        temp = head->next->next;
        pre->next = head->next;
        head->next->next = pre = head;
        head->next = temp;
        head = head->next;
    }
    return start;
}
