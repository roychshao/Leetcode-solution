void dfs(struct TreeNode* root, int *output, int *returnSize)
{
    if(root == NULL)  return;
    dfs(root->left,output,returnSize);
    output[(*returnSize)++] = root->val;
    dfs(root->right,output,returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int* output = (int*)malloc(sizeof(int) * 100);
    memset(output,NULL,sizeof(output));
    dfs(root,output,returnSize);
    return output;
}
