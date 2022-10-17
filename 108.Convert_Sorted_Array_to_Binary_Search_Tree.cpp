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

    void Insert(TreeNode* node, int val) {
        if(!node)
            return;
        if(val > node->val && node->right) {
            Insert(node->right, val);
        }
        if(val < node->val && node->left) {
            Insert(node->left, val);
        }
        if(val > node->val && !node->right) {
            TreeNode* tmp = new TreeNode(val);
            node->right = tmp;
        }
        if(val < node->val && !node->left) {
            TreeNode* tmp = new TreeNode(val);
            node->left = tmp;
        }
    }

    void getHalf(TreeNode* root, int head, int tail, vector<int> nums) {
        int mid = (head + tail) / 2;
        /*
        cout << "head: " << head << endl;
        cout << "mid: " << mid << endl;
        cout << "tail: " << tail <<endl << endl;
        */
        Insert(root, nums[mid]);
        if(head != mid) {
            getHalf(root, head, mid, nums);
            getHalf(root, mid, tail, nums);
        }
        return;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode;
        int size = nums.size();
        root->val = nums[size/2];
        getHalf(root, 0, size/2, nums);
        getHalf(root, size/2, size, nums);
        return root;
    }
};
