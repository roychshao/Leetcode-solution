/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode pre = null;
        ListNode cur = head;
        ListNode leftborder = null;
        ListNode leftest = null;
        int idx = 1;
        if (left == right) return head;
        while (cur != null) {
            if (idx == left) {
                leftborder = pre;
                leftest = cur;
            }
            if (idx == right) {
                ListNode nxt = cur.next;
                leftest.next = nxt;
                cur.next = pre;
                if (leftborder != null) {
                    leftborder.next = cur;
                } else {
                    head = cur;
                } 
                break;
            }
            if (idx > left && idx < right) {
                // reverse
                ListNode nxt = cur.next;
                cur.next = pre;
                pre = cur;
                cur = nxt;
            } else {
                pre = cur;
                cur = cur.next;
            }
            idx++;
        }
        return head;
    }
}
