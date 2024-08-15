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

    public List<TreeNode> BFS(List<TreeNode> currentLevel) {
        List<TreeNode> nextLevel = new ArrayList<>();

        for (int i = 0; i < currentLevel.size(); ++i) {
            if (currentLevel.get(i).left != null) {
                nextLevel.add(currentLevel.get(i).left);
            }
            if (currentLevel.get(i).right != null) {
                nextLevel.add(currentLevel.get(i).right);
            }
        }
        return nextLevel;

    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        List<TreeNode> currentLevel = new ArrayList<>();
        boolean forward = true;

        if (root == null) {
            return res;
        }
        currentLevel.add(root);
        List<Integer> firstLevelInt = new ArrayList<>();
        firstLevelInt.add(root.val);
        res.add(firstLevelInt);
        forward = !forward;

        while (!currentLevel.isEmpty()) {
            List<TreeNode> nextLevel = BFS(currentLevel);
            List<Integer> nextLevelInt = new ArrayList<>();
            if (forward) {
                for (int i = 0; i < nextLevel.size(); ++i) {
                    nextLevelInt.add(nextLevel.get(i).val);
                }
            } else {
                for (int i = nextLevel.size() - 1; i >= 0; --i) {
                    nextLevelInt.add(nextLevel.get(i).val);
                }
            }
            forward = !forward;
            if (!nextLevelInt.isEmpty())
                res.add(nextLevelInt);
            currentLevel = nextLevel;
        }
        return res;
    }
}
