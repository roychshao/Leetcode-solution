int maxdepth;

void traversal(int depth, struct TreeNode* node)
{
    if(node == NULL)
        return;
    maxdepth = (maxdepth > depth) ? maxdepth : depth;
    traversal(depth+1, node->left);
    traversal(depth+1, node->right);
}

int maxDepth(struct TreeNode* root)
{
    maxdepth = 0;
    if(root == NULL)
        return 0;
    traversal(1,root);
    return maxdepth;
}
