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
    public ListNode partition(ListNode head, int x) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        ListNode current = head;
        while (current != null) {
            if (current.val < x) {
                list1.add(current.val);
            } else {
                list2.add(current.val);
            }
            current = current.next;
        }
        current = head;
        while (current != null) {
            for (int i = 0; i < list1.size() && current != null; ++i) {
                current.val = list1.get(i);
                current = current.next;
            }
            for (int j = 0; j < list2.size() && current != null; ++j) {
                current.val = list2.get(j);
                current = current.next;
            }
        }
        return head;
    }
}
