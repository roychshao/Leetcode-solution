
/*
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
    ListNode* rotateRight(ListNode* head, int k) {
        int listlen = 0;
        int cutPlace;
        int counter = 1;
        ListNode* tail = head;
        while(tail && tail->next) {
            listlen++;
            tail = tail->next;
        }
        listlen++;  // correct
        //cout << "listlen: " << listlen << endl;
        k %= listlen;
        if(k == 0)
            return head;
        cutPlace = listlen - k;
        //cout << "cutPlace: " << cutPlace << endl;
        ListNode* newTail = head;
        while(counter != cutPlace) {
            newTail = newTail->next;
            counter++;
        }
        //cout << "counter: " << counter << endl;
        ListNode* newHead = newTail->next;
        tail->next = head;
        newTail->next = NULL;
        return newHead;
    }
};
