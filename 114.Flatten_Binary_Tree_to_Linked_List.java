/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {
  public void flatten(TreeNode node) {
    if (node == null) return;
    if (node.left != null) {
      TreeNode rightest = node.left;
      while (rightest.right != null) {
        rightest = rightest.right;
      }
      rightest.right = node.right;
      node.right = node.left;
      node.left = null;
    }
    flatten(node.right);
  }
}
