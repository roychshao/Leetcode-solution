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

    void reverse(ListNode* Pre, ListNode* Next){
        ListNode* current = Pre->next;
        ListNode* nnext = Next;
        while(current != Next){
            Pre->next = current->next;
            current->next = nnext;
            nnext = current;
            current = Pre->next;
        }
        Pre->next = nnext;
        current = Pre;
        cout << endl;
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* idx = head;
        int length = 0;
        while(idx != NULL){
            length++;
            idx = idx->next;
        }
        if(length == 1)
            return head;
        ListNode dump(-1);
        ListNode* root = &dump;
        root->next = head;
        ListNode* Pre = root, *Next = head;
        for(int i = 0; i < k; ++i)
            Next = Next->next;
        for(int i = 0; i < length/k; ++i){
            reverse(Pre, Next);
            for(int j = 0; j < k; ++j){
                Pre = Pre->next;
                if(Next)
                    Next = Next->next;
            }
        }
        return root->next;
    };
};

