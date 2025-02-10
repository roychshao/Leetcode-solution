/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode() {}
 * ListNode(int val) { this.val = val; } ListNode(int val, ListNode next) { this.val = val;
 * this.next = next; } }
 */
import java.util.*;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {

  TreeNode TreeHead;

  public void addNode(TreeNode head, Integer val) {
    if (val > head.val) {
      if (head.right == null) {
        head.right = new TreeNode(val);
      } else {
        addNode(head.right, val);
      }
    } else {
      if (head.left == null) {
        head.left = new TreeNode(val);
      } else {
        addNode(head.left, val);
      }
    }
  }

  public void addByOrder(List<Integer> arr, int head, int tail) {
    if (head == tail) return;
    int mid = (head + tail) / 2;
    TreeNode curr = new TreeNode(arr.get(mid));
    if (mid == arr.size() / 2) {
      TreeHead = curr;
    } else {
      addNode(TreeHead, arr.get(mid));
    }
    addByOrder(arr, head, mid);
    addByOrder(arr, mid + 1, tail);
  }

  public TreeNode sortedListToBST(ListNode head) {
    List<Integer> arr = new ArrayList<>();
    while (head != null) {
      arr.add(head.val);
      head = head.next;
    }
    addByOrder(arr, 0, arr.size());
    return TreeHead;
  }
}
