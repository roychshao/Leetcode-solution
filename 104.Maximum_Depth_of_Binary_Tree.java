/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {

    private int maxDep = 1;

    public void traverse(TreeNode root, int depth) {
        if (root == null)
            return;
        maxDep = Math.max(maxDep, depth);
        traverse(root.left, depth + 1);
        traverse(root.right, depth + 1);
    }

    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        traverse(root, 1);
        return maxDep;
    }
}
