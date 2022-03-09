
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
class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *i = head, *j = head->next;
        ListNode *ipre = head, *jpre = head;
        bool i_duplicate = false;
        if(!j)
            return head;
        while(i != NULL){
            while(j != NULL){
                if(i->val == j->val){
                    i_duplicate = true;
                    jpre->next = j->next;
                }else{
                    jpre = j;
                }
                j = j->next;
            }
            if(i_duplicate){
                if(i != head)
                    ipre->next = i->next;
                else
                    head = head->next;
                i_duplicate = false;
            }else
                ipre = i;
            if(!i->next || !i)
                break;
            i = i->next;
            j = i->next;
            jpre = i;
        }
        return head;
    };
};
