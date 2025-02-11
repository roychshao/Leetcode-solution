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

  public void dfs(Node node) {
    if (node == null) return;
    if (node.left != null && node.right != null) node.left.next = node.right;
    if (node.right != null && node.next != null) node.right.next = node.next.left;
    dfs(node.left);
    dfs(node.right);
  }

  public Node connect(Node root) {
    dfs(root);
    return root;
  }
}
