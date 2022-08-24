class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            string str = "";
            while(head) {
                str += head->val;
                head = head->next;
            }
            string rev_str = str;
            reverse(rev_str.begin(), rev_str.end());
            if(str == rev_str)
                return true;
            else 
                return false;
        }
};
