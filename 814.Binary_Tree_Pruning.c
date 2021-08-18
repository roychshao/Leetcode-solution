/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool dfs(struct TreeNode* node)
{
    if(!node)   return false;
    bool leftContainOne = dfs(node->left);
    bool rightContainOne = dfs(node->right);
    if(!leftContainOne) node->left = NULL;
    if(!rightContainOne)    node->right = NULL;
    return node->val == 1 || leftContainOne || rightContainOne;
}

struct TreeNode* pruneTree(struct TreeNode* root)
{
    return dfs(root) ? root : NULL;
}
