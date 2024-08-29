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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }

        int[] index = { postorder.length - 1 };

        return helper(postorder, inorder, 0, postorder.length - 1, map, index);
    }

    private static TreeNode helper(int[] postorder, int[] inorder, int left, int right, HashMap<Integer, Integer> map,
            int[] index) {
        if (left > right) {
            return null;
        }

        int curr = postorder[index[0]];
        index[0]--;

        TreeNode node = new TreeNode(curr);

        if (left == right) {
            return node;
        }

        int inorderIndex = map.get(curr);
        node.right = helper(postorder, inorder, inorderIndex + 1, right, map, index);
        node.left = helper(postorder, inorder, left, inorderIndex - 1, map, index);

        return node;
    }
}
