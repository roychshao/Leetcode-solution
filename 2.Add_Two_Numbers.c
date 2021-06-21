/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void add(int temp,struct ListNode* l3)
{
    struct ListNode* current = l3;
    while(current != NULL)
        current = current->next;
    current=(struct ListNode *) malloc(sizeof(struct ListNode));
    current->val = temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int val1 = 0,val2 = 0,val3 = 0,flag = 0;    
    struct ListNode* current1 = l1;
    struct ListNode* current2 = l2;
    struct ListNode* l3 = NULL;
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    while(current1 != NULL || current2 != NULL)
    {
        val1 = current1->val;
        val2 = current2->val;
        int temp = val1 + val2;
        if(temp >= 10)
        {
            if(flag)
                add(temp - 9,l3);
            else
                add(temp - 10,l3);
            flag = 1;
        }
        else
        {
            if(flag)
                add(temp  + 1,l3);
            else
                add(temp,l3);
            flag = 0;
        }
        if(current1 != NULL)
            current1 = current1->next;
        if(current2 != NULL)
            current2 = current2->next;
    }
    return l3;
}
