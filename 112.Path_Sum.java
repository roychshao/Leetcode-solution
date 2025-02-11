/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {

  public boolean result = false;

  public void dfs(TreeNode node, int targetSum, int tmpSum) {
    if (node == null) return;

    // if leaf
    if (node.left == null && node.right == null) {
      // if fulfilled
      if (node.val + tmpSum == targetSum) {
        result = true;
      }
    }

    dfs(node.left, targetSum, tmpSum + node.val);
    dfs(node.right, targetSum, tmpSum + node.val);
  }

  public boolean hasPathSum(TreeNode root, int targetSum) {
    dfs(root, targetSum, 0);
    return result;
  }
}
