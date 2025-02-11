/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {

  public List<List<Integer>> result = new ArrayList<>();

  public void dfs(TreeNode node, int targetSum, List<Integer> tmpList) {
    if (node == null) return;

    tmpList.add(node.val);

    // if leaf
    if (node.left == null && node.right == null) {
      // if fulfilled
      int tmpSum = 0;
      for (Integer i : tmpList) {
        tmpSum += i;
      }
      if (tmpSum == targetSum) {
        result.add(new ArrayList<>(tmpList));
      }
    }

    dfs(node.left, targetSum, tmpList);
    dfs(node.right, targetSum, tmpList);
    tmpList.removeLast();
  }

  public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
    dfs(root, targetSum, new ArrayList<>());
    return result;
  }
}
