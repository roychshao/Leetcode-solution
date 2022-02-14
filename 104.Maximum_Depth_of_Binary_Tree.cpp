/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth = 0;

    void traverse(TreeNode *node, int depth){
        maxdepth = (depth > maxdepth) ? depth : maxdepth;
        if(node->left != NULL)
            traverse(node->left, depth+1);
        if(node->right != NULL)
            traverse(node->right, depth+1);
    };

    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        traverse(root, 1);
        return maxdepth;
    };
};
