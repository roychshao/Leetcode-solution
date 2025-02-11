/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
  public Node connect(Node root) {
    if (root == null) return null;

    Node dummy = new Node(); // Dummy node to track the next level
    Node cur = root; // Start at the root

    while (cur != null) {
      Node temp = dummy; // Use dummy to build the next level
      while (cur != null) {
        if (cur.left != null) { // Link the left child
          temp.next = cur.left;
          temp = temp.next;
        }
        if (cur.right != null) { // Link the right child
          temp.next = cur.right;
          temp = temp.next;
        }
        cur = cur.next; // Move to the next node in the current level
      }
      cur = dummy.next; // Move to the next level
      dummy.next = null; // Reset dummy for the next level
    }

    return root;
  }
}
