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
    int min = 100000;
    
    void dfs(TreeNode* node, int depth) {
        if(!node->left && !node->right)
            min = (depth < min) ? depth : min;
        if(node->left)
            dfs(node->left, depth+1);
        if(node->right)
            dfs(node->right, depth+1);
    }

    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root, 1);
        return min;
    }
};
