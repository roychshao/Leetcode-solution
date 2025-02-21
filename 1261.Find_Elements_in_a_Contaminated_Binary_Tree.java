/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class FindElements {

  private TreeNode root = null;

  public void recover(TreeNode node, int val) {
    if (node == null) return;
    // System.out.println("val: " + val);
    node.val = val;
    recover(node.left, (2 * val) + 1);
    recover(node.right, (2 * val) + 2);
  }

  public boolean findRecursive(TreeNode node, int target) {
    if (node == null) return false;
    if (node.val == target) {
      return true;
    } else {
      return (findRecursive(node.left, target) || findRecursive(node.right, target));
    }
  }

  public FindElements(TreeNode root) {
    if (root == null) {
      return;
    }
    this.root = root;
    recover(root, 0);
  }

  public boolean find(int target) {
    return findRecursive(root, target);
  }
}

/**
 * Your FindElements object will be instantiated and called as such: FindElements obj = new
 * FindElements(root); boolean param_1 = obj.find(target);
 */
