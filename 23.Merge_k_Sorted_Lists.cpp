
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

    ListNode* mergeKLists(vector<ListNode*> &lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it:lists){
            while(it){
                pq.push(it->val);
                it = it->next;
            }
        }
        ListNode root(0);
        ListNode* current = &root;
        while(!pq.empty()){ 
            ListNode* val = new ListNode(pq.top());
            current->next = val;
            current = current->next;
            pq.pop();
        }
        return root.next;
    }
};
