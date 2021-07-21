
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int idx;

void record(struct TreeNode* node, int *arr)
{
        if(node == NULL)
        {
            arr[idx++] = 'X';
            return;
        }
        arr[idx++] = node->val;
        record(node->left, arr);
        record(node->right, arr);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
        idx = 0;
        int ptree[300], qtree[300];
        memset(ptree,NULL,sizeof(ptree));
        memset(qtree,NULL,sizeof(qtree));
        record(p,ptree);
        idx = 0;
        record(q,qtree);
        puts(ptree);
        puts(qtree);
        return (memcmp(ptree,qtree,sizeof(ptree)) == 0) ? true : false;
}
