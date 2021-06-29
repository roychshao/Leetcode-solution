/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void rm(struct ListNode* pre)
{
    struct ListNode* target = pre->next;
    struct ListNode* temp = target->next;
    pre->next = temp;
    free(target);
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* current = head;
    int sz = 1,counter = 1;
    while(current->next != NULL)
    {
        current = current->next;
        sz++;
    }
    current = head;
    int target = (sz - n);
    if(target == 0)
    {
        struct ListNode* temp = head->next;
        free(head);
        return temp;
    }
    while(counter != target)
    {
        current = current->next;
        counter++;
    }
    rm(current);
    return head;
}
