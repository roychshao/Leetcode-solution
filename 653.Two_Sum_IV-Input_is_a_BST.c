/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int nums[10000];
int idx;

void inorder(struct TreeNode* node)
{
    if(!node)   return;
    inorder(node->left);
    inorder(node->right);
    nums[idx++] = node->val;
}

int cmp(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool findTarget(struct TreeNode* root, int k)
{
    memset(nums, 0, sizeof(int));
    idx = 0;
    inorder(root);
    qsort(nums, idx, sizeof(int), cmp);
    int head = 0, tail = idx - 1;
    while(head < tail)
    {
        if((nums[head] + nums[tail]) > k)
            tail--;
        else if((nums[head] + nums[tail]) < k)
            head++;
        else
            return true;
    }
    return false;
}
