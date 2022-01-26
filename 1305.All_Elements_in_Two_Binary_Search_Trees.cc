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
    vector<int> list1, list2;
    void traversal1(TreeNode* node){
        if(node == NULL)
            return;
        if(node->left != NULL)
            traversal1(node->left);
        list1.push_back(node->val);
        if(node->right != NULL)
            traversal1(node->right);
    };
    
    void traversal2(TreeNode* node){
        if(node == NULL)
            return;
        if(node->left != NULL)
            traversal2(node->left);
        list2.push_back(node->val);
        if(node->right != NULL)
            traversal2(node->right);
    };
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        traversal1(root1);
        traversal2(root2);
        /*for(auto it=list1.begin();it!=list1.end();++it)
            cout << *it << " ";
        cout << endl;
        for(auto it=list2.begin();it!=list2.end();++it)
            cout << *it << " ";
        cout << endl;*/
        int i=0, j=0;
        if(list1.size() == 0)
            return list2;
        else if(list2.size() == 0)
            return list1;
        while(i<list1.size() && j<list2.size()){
            if(list1[i] <= list2[j]){
                ans.push_back(list1[i]);
                i++;
            }
            else{
                ans.push_back(list2[j]);
                j++;
            }
            if(i == list1.size()){
                while(j<list2.size()){
                    ans.push_back(list2[j]);
                    j++;
                }
            }
            if(j == list2.size()){
                while(i<list1.size()){
                    ans.push_back(list1[i]);
                    i++;
                }
            }
        }
        return ans;
    };
};
