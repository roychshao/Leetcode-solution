/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ans;

void dfs(struct TreeNode* node, int maxval)
{
    if(!node)   return;
    if(node->val >= maxval)
        ans++, maxval = node->val;
    dfs(node->left, maxval);
    dfs(node->right, maxval);
}

int goodNodes(struct TreeNode* root)
{
    ans = 0;
    dfs(root, -10001);
    return ans;
}
