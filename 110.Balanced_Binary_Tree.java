/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {

  public boolean flag = true;

  public int dfs(TreeNode node) {
    if (node == null) return -1;
    int leftHeight = dfs(node.left);
    int rightHeight = dfs(node.right);

    // if not balanced, modfy the flag
    if ((leftHeight - rightHeight) > 1 || (leftHeight - rightHeight) < -1) {
      flag = false;
    }

    node.val = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    return node.val;
  }

  public boolean isBalanced(TreeNode root) {
    int height = dfs(root);
    return flag;
  }
}
